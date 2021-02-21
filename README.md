# OCS10-Techniques-and-Algorithms
OCS10 C++: Techniques &amp; Algorithms semester 1 final project Caesar Cipher. 

A Caesar Cipher takes a message and shifts each character a fixed number of characters in the alphabet. For example, if the message is "I love pizza!" and the cipher takes a right shift of 1, then the encrypted message becomes "J mpwf qjaab!". The letter 'z' wraps around to become letter 'a'. Punctuation and spaces remain the same. 

This program enciphers and deciphers messages. To encipher, it takes in user input for number of letter shifts for the message. To decipher a message, the program requires no user input of shifts and uses a letter frequency algorithm to find the appropriate version of the deciphered message for standard English.

The program includes the main `string encipher(string str, int n)` and `string decipher(string str)` functions which encrypt and decrypt message using the Caesar Cipher method. A helper function `char rotate(unsigned char ch, int n)` is used that rotates a character n spots to the right (working with capitals and lowercase with appropriate wrap around and no change for spaces and punctuation). Finally, the helper function `double letterScore(char ch)` in deciphering that produces a number based on letter frequencies in modern English. It employs the `encipher()` method on the encrypted phrase for doing all letter shifts of 1 to 25 and giving each a score. The correct original phrase should have the highest score, so it is choosen as the most likely original message and is printed to the user.

Here is a sample run of the program:

*This is a Caesar Cipher that enciphers (and deciphers) phrases based on a given number of shifts in the alphabet
(after Z wraps back around to A). Any character that is not a letter remains the same. Upper/lower case do as well.*

*What would you like to do? Select the corresponding number.*

*1. Encipher*

*2. Decipher*

*3. Quit*

*1*

*Enter the phrase you would like to encipher:*

*Hello, how are you today?*

*Enter the alphabet shift to the right. Enter an integer between 1 and 25:*

*4*

*The enciphered phrase is: Lipps, lsa evi csy xshec?*

*What would you like to do? Select the corresponding number.*

*1. Encipher*

*2. Decipher*

*3. Quit*

*2*

*Enter the phrase you would like to decipher. (Some inaccuracy may occur if the expression is very short):*

*Lipps, lsa evi csy xshec?*

*The deciphered phrase is: Hello, how are you today?*

*What would you like to do? Select the corresponding number.*

*1. Encipher*

*2. Decipher*

*3. Quit*

*3*

*You have quit the program.*

