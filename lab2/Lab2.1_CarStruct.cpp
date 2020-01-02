#/*
Iraj Shrotri
Summer 2019
Lab 2
Problem 2.1

*/

#include <iostream>
#include <string>
 
using namespace std;

struct Car {
	string reportingMark;		//a string of 5 or less upper case characters
	int	carNumber; 	  			//an int
	string kind; 	  			//could be box, tank, flat, or other
	bool loaded; 	  			//a bool
	string destination; 	 	//a string with a destination or the word NONE
};

void input(Car*);
void output(Car*);

int main() {
	Car *yeet = new Car;
	input(yeet);
	output(yeet);
	delete yeet;
	system("pause");
	return 0;
}

void input(Car *ptr) {
	string temp, temp2, temp3 = "ouuuu";

	cout << "Insert reporting mark (string of 5 or less upper case characters)" << endl;
	//cin >> ptr->reportingMark;
	cin >> temp2;
	int inputSize = 5, index = 0;	// initialize size and increment variables
	while (index != inputSize) {
		if (temp2[index] >= 97 && temp2[index] <= 122) {
			temp3[index] = temp2[index] - 32;
			index++;
		}
	}
	ptr->reportingMark = temp3;

	cout << "Insert car number (int)" << endl;
	cin >> ptr->carNumber;

	cout << "Insert kind (box, tank, flat, or other)" << endl;
	cin >> ptr->kind;

	cout << "Insert loaded (true/false)" << endl;
	cin >> temp;
	if (temp == "true") {
		ptr->loaded = 1;
	}
	else {
		ptr->loaded = 0;
	}

	cout << "Insert destination (string with a destination or the word NONE)" << endl;
	cin >> ptr->destination;

	return;			// returns ptr to dyn all mem
}


void output(Car *ptr) {
	cout << endl;
	cout << "************************************" << endl;
	cout << "------------Car Data----------------" << endl;
	cout << "************************************" << endl;

	cout << "Reporting mark: \t" << ptr->reportingMark << endl;

	cout << "Car number: \t \t" << ptr->carNumber << endl;

	cout << "Kind: \t \t \t" << ptr->kind << endl;

	if (ptr->loaded == true) {
		cout << "Loaded: \t \ttrue" << endl;
	}
	else {
		cout << "Loaded: \t \t false" << endl;
	}

	cout << "Destination: \t \t" << ptr->destination << endl;
}




