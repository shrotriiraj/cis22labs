/*
Iraj Shrotri
Summer 2019
Lab 1
Problem 0.0.0
Description of problem:
input <- takes in user message and stores it in dynamic all mem, returns ptr
encrypt <- preforms ROT13 encryption on user message and stores new message in dynamic all mem
output <- outputs message in dyn all mem
main <- 
*/

#include <iostream>
#include <string>
#include <memory>
#include <utility>   

using namespace std;

string *input() {
	string *based;			// declare ptr
	based = new string;		// dynamically allocate memory

	cout << "Insert string pls" << endl;
	cin.ignore();			// <<---Input stream still had a '\n' in it so cin took that as input.
							// cin.ignore() clear the buffer so that doesn't happen
	getline(cin, *based);	// stores user input in dyn all mem
	return based;			// returns ptr to dyn all mem
}

void encrypt(string *preEncryptPtr) {
	string preEncrypt = *preEncryptPtr;		// temp string to hold the pointer's val
	//cout << preEncrypt << "\n";			// cout for testing

	int inputSize = preEncrypt.size(), index = 0;	// initialize size and increment variables

	while ( index != inputSize ) {					// itterates through entire loop
		if (preEncrypt[index] == 32) {				// case for SPACE
			index++;
		}
		else if (preEncrypt[index] >= 65 && preEncrypt[index] <= 77) {			// case for A-M
			preEncrypt[index] = preEncrypt[index] + 13;
			index++;		// increment
		}
		else if (preEncrypt[index] >= 78 && preEncrypt[index] <= 90) {		// case for N-Z
			preEncrypt[index] = preEncrypt[index] - 13;
			index++;		// increment
		}
		else if (preEncrypt[index] >= 97 && preEncrypt[index] <= 109) {		// case for a-m
			preEncrypt[index] = preEncrypt[index] + 13;
			index++;		// increment
		}
		else if (preEncrypt[index] >= 110 && preEncrypt[index] <= 122) {	// case for n-z
			preEncrypt[index] = preEncrypt[index] - 13;
			index++;		// increment
		}
	}
	//cout << preEncrypt << "\n";			// cout for testing
	*preEncryptPtr = preEncrypt;			// puts decoded/encrypted message back in the dyn all mem

	return;
}

void output(string *ptr){			
	cout << *ptr << "\n";		// couts it
};


int main() {
	string affirmation, *untransptr;	 // declare strings
	cout << "Do you want to use ROT13 on a string? (if not input no or No)" << endl;
	cin >> affirmation;	

	if (!(affirmation == "no" || affirmation == "No")) {	// ends branch if input is no or No
		untransptr = input();		// untransptr -> pointer for dyn all mem
		//cout << untransptr << "\n"; // cout the address for ptr for testing
		encrypt(untransptr);		// calls encrypt function
		output(untransptr);			// calls output function
		delete untransptr;			// deletes dynamically allocated mem // prevents mem leak
		cout << "Message encoded/decoded!" << "\n";
	}
	else {
		cout << "OK nevermind." << "\n";
	}

	system("pause");
	return 0;
}


