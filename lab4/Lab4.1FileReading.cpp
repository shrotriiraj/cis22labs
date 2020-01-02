/*
Iraj Shrotri
Summer 2019
Lab 4
Problem 4.1

*/

#include <fstream>
#include <iostream>
#include <string>
#include "cardata.txt"

using namespace std;

class Car {
private:
	string reportingMark;		//a string of 5 or less upper case characters
	int	carNumber; 	  			//an int
	string kind; 	  			//could be box, tank, flat, or other
	bool loaded; 	  			//a bool
	string destination; 	 	//a string with a destination or the word NONE

public:
	// Constructors
	Car() {						//default
		reportingMark = "None";
		carNumber = 0;
		kind = "None";
		loaded = false;
		destination = "None";
	}
	Car(Car &copy) {			//copy
		reportingMark = copy.reportingMark;
		carNumber = copy.carNumber;
		kind = copy.kind;
		loaded = copy.loaded;
		destination = copy.destination;
	}
	Car(string mark, int num, string make, bool state, string dest) {	//unique instance
		setUp(mark, num, make, state, dest);
	}
	// Destructor
	~Car() {};


	/*
	// Mutator member function prototypes
	void setReportingMark(string mark) {
		reportingMark = mark;
	}
	void setCarNumber(int num) {
		carNumber = num;
	}
	void setKind(string make) {
		kind = make;
	}
	void setLoaded(bool state) {
		loaded = state;
	}
	void setDestination(string dest) {
		destination = dest;
	}

	// Accessor member function prototypes
	string getReportingMark() const {
		return reportingMark;
	}
	int getCarNumber() const {
		return carNumber;
	}
	string getKind() const {
		return kind;
	}
	bool getLoaded() const {
		return loaded;
	}
	string getDestination() const {
		return destination;
	}
	*/

	// Class specific function
/* ******************** setUpCar ********************
creates an object using a constructor that takes the reference
parameters pointer to the object c1 returned.
*/
	void setUp(string &mark, int &num, string &make, bool &state, string &dest) {
		reportingMark = mark;
		carNumber = num;
		kind = make;
		loaded = state;
		destination = dest;
		return;
	}; // end setUpCar

	void output() {
		cout << endl;
		//cout << "************************************" << endl;
		//cout << "------------Car Data----------------" << endl;
		//cout << "************************************" << endl;


		cout << "\t Reporting mark: \t" << reportingMark << endl;

		cout << "\t Car number: \t \t" << carNumber << endl;

		cout << "\t Kind: \t \t \t" << kind << endl;

		//cout << "Loaded: " << ptr-> getLoaded() << endl;
		if (loaded == true) {
			cout << "\t Loaded: \t \ttrue" << endl;
		}
		else {
			cout << "\t Loaded: \t \tfalse" << endl;
		}

		cout << "\t Destination: \t \t" << destination << endl;
		cout << endl;
	}

	friend bool operator ==(Car first, Car second) {
		bool temp = false;
		if (first.carNumber == second.carNumber &&
			first.destination == second.destination &&
			first.kind == second.kind &&
			first.loaded == second.loaded &&
			first.reportingMark == second.reportingMark) {
			temp = true;
		}
		return temp;
	}
};

void input();

int main() {
	input();
	system("pause");
	return 0;
}

void input() {
	ifstream inputFile;
	inputFile.open("cardata.txt");
	if (!inputFile.is_open()) {
		cerr << "File didn't open" << endl;
		return;
	}

	string mark;
	int num;
	string make;
	bool state;
	string dest;
	string temp, temp2 = "     ";
	string type;

while (inputFile.peek() != EOF){
		inputFile >> type;
		inputFile >> mark;
		int index = 0, inputSize = 5;	// initialize size and increment variables
		if (mark.size() < 5) {
			inputSize = mark.size();
		}
		while (index != inputSize) {
			if (mark[index] == 32) {
				index++;
			}
			else if (mark[index] >= 97 && mark[index] <= 122) {
				temp2[index] = mark[index] - 32;
				index++;
			}
			else {
				temp2[index] = mark[index];
				index++;
			}
		}
		mark = temp2;

		inputFile >> num;

		inputFile >> make;

		inputFile >> std::boolalpha >> state;

		getline(inputFile, dest);
	
		Car temp3(mark, num, make, state, dest);
		temp3.output();
}
	inputFile.close();

	return;
}

