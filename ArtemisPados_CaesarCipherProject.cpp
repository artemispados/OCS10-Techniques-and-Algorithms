/*This program is a Caesar Cipher. It enciphers and deciphers messages. It enciphers based on user input of number of letter shifts in the alphabet
and deciphers messages with no user input of shifts (just based on letter frequency 
algorithm).*/
#include<iostream>
#include <string>
#include<cmath>
using namespace std;

char rotate(unsigned char ch, int n);
string encipher(string str, int n);
string decipher(string str);
double score(string str);
double letterScore(char ch);

int main()
{
	int op, n;
	string str;
	
	cout<<"This is a Caesar Cipher that enciphers (and deciphers) phrases based on a given number of shifts in the alphabet"<<endl;
	cout<<"(after Z wraps back around to A). Any character that is not a letter remains the same. Upper/lower case do as well."<<endl;
	
	while (op!=3) //menu
	{
		cout<<"What would you like to do? Select the corresponding number."<<endl;
		cout<<"1. Encipher"<<endl;
		cout<<"2. Decipher"<<endl;
		cout<<"3. Quit"<<endl;
		cin>>op;
		
		switch (op)
		{
			case 1: cout<<"Enter the phrase you would like to encipher: "<<endl; //encipher
					cin.ignore();
					getline(cin,str);
					cout<<"Enter the alphabet shift to the right. Enter an integer between 1 and 25: "<<endl;
					cin>>n;
					do {
						if(n<1||n>25) //invalid input for shift
						{
							cout<<"Invalid input. Enter an integer between 1 and 25 for the shift: "<<endl;
							cin>>n;
						}
					} while(n<1||n>25);
					cout<<"The enciphered phrase is: "<<encipher(str,n)<<endl;
					break;
			case 2: cout<<"Enter the phrase you would like to decipher. (Some inaccuracy may occur if the expression is very short): "<<endl; //decipher
					cin.ignore();
					getline(cin,str);
					cout<<"The deciphered phrase is: "<<decipher(str)<<endl;
					break;
			case 3: cout<<"You have quit the program."<<endl; //quit
					break;
			default: cout<<"Invalid input. Enter a number that corresponds to an option."<<endl; //if menu selection invalid
		}
	}
	return 0;
}

char rotate(unsigned char ch, int n) //shifts character given steps to the right
{
	if (ch>='A'&&ch<='Z') //uppercase letter
	{
		ch=ch+n;
		if (ch>'Z') //to wrap around
			ch='A'-1+ch-'Z';
	}
	else if (ch>='a'&&ch<='z') //lowercase letter
	{
		ch=ch+n;
		if (ch>'z') //to wrap around
			ch='a'-1+ch-'z';
	}
	else //not letter
		ch=ch;
	
	return ch;
}

string encipher(string str, int n) //encipher string function
{
	string stri;
	for (int i=0; i<str.length();i++) //traverses string by letter
		stri+=rotate(str[i],n); //appends rotated letter at end of string
	return stri;
}

string decipher(string str) //decipher string function
{
	string enc;
	double highest=0;
	for (int i=1; i<26; i++) //make 25 diff enciphers
	{
		enc=encipher(str,i);
		score(enc); //score of that encipher
		if (score(enc)>highest)
			highest=score(enc); //highest score up to that point
	}
	for (int i=1; i<26; i++) //finds string with highest score
	{
		enc=encipher(str,i);
		score(enc);
		if (highest==score(enc))
			return enc;
	}
}

double score(string str) //score of string function
{
	double score=0;
	for (int i=0; i<str.length();i++) //traverses string by letter
		score+=letterScore(str[i]); //adds score of letter to total score
	return score;
}

double letterScore(char ch) //score of individual letters function
{
	if (ch == 'A' || ch == 'a') return .0684;
	if (ch == 'B' || ch == 'b') return .0139;
	if (ch == 'C' || ch == 'c') return .0146;
	if (ch == 'D' || ch == 'd') return .0456;
	if (ch == 'E' || ch == 'e') return .1267;
	if (ch == 'F' || ch == 'f') return .0234;
	if (ch == 'G' || ch == 'g') return .0180;
	if (ch == 'H' || ch == 'h') return .0701;
	if (ch == 'I' || ch == 'i') return .0640;
	if (ch == 'J' || ch == 'j') return .0033;
	if (ch == 'K' || ch == 'k') return .0093;
	if (ch == 'L' || ch == 'l') return .0450;
	if (ch == 'M' || ch == 'm') return .0305;
	if (ch == 'N' || ch == 'n') return .0631;
	if (ch == 'O' || ch == 'o') return .0852;
	if (ch == 'P' || ch == 'p') return .0136;
	if (ch == 'Q' || ch == 'q') return .0004;
	if (ch == 'R' || ch == 'r') return .0534;
	if (ch == 'S' || ch == 's') return .0659;
	if (ch == 'T' || ch == 't') return .0850;
	if (ch == 'U' || ch == 'u') return .0325;
	if (ch == 'V' || ch == 'v') return .0084;
	if (ch == 'W' || ch == 'w') return .0271;
	if (ch == 'X' || ch == 'x') return .0007;
	if (ch == 'Y' || ch == 'y') return .0315;
	if (ch == 'Z' || ch == 'z') return .0004;
	return 0.0;
}
