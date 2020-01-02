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

		cout << "\t Destination: \t " << destination << endl;
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
	// Car  operator=  **************************************************
	Car operator=(const Car & carB) {
		reportingMark = carB.reportingMark;
		carNumber = carB.carNumber;
		kind = carB.kind;
		loaded = carB.loaded;
		destination = carB.destination;

		return *this;
	}
};

class StringOfCars{
	private:
		Car *carPtr;
		static const int ARRAY_MAX_SIZE = 10;
		int size = 0;
		Car array[10];
	public:
		StringOfCars() {
			size = 0;
			carPtr = &array[size];
		}
		StringOfCars(StringOfCars &car) {
			carPtr = new Car[ARRAY_MAX_SIZE];
			for (int i = 0; i < size; i++) {
				carPtr[i] = car.carPtr[i];
			}
		}
		~StringOfCars() {}

		void push (Car car) {
			if (size >= 10) {
				return;
			}
			carPtr[size] = car;
			size++;
		};
		void pop(Car &car) {
			if (size == 0)
				return;
			car = carPtr [size-1];
			size--;
		}
		void outputStringofCars() {
			if (size == 0) {
				cout << "NO CARS" << endl;
			}
			else {
				for (int j = 0; j < size; j++) {
					cout << "Car # " << (j+1) << endl;
					carPtr[j].output();
				}
			}
		}
};

/*

*/

void input(StringOfCars &);

int main() {
	cout << "TEST #1" << endl;
	Car car1("SP", 34567, "box", true, "Salt Lake City");
	Car car2 = car1;
	car2.output();

	cout << "TEST #2" << endl;
	StringOfCars string1;
	input(string1);
	string1.outputStringofCars();

	cout << "TEST #3" << endl;
	Car car3;
	string1.pop(car3);
	cout << "CAR 3" << endl;
	car3.output();
	string1.outputStringofCars();

	system("pause");
	return 0;
}

void input(StringOfCars &str) {
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

	while (inputFile.peek() != EOF) {
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
		//temp3.output();
		str.push(temp3);
	}
	inputFile.close();

	return;
}

