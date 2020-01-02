
#include <fstream>
#include <iostream>
#include <string>
#include "cardata5.txt"

using namespace std;

enum Kind { business, maintenance, other, box, tank, flat, otherFreight, chair, sleeper, otherPassenger };
const int ARRAY_SIZE = 10;
const string KIND_ARRAY[ARRAY_SIZE] = { "business", "maintenance", "other",
	"box", "tank", "flat", "otherFreight", "chair", "sleeper", "otherPassenger" };

class Car {
protected:
	string reportingMark;		//a string of 5 or less upper case characters
	int	carNumber; 	  			//an int
	Kind kind; 	  				//could be box, tank, flat, or other
	bool loaded; 	  			//a bool
	string destination; 	 	//a string with a destination or the word NONE

public:
	// Constructors
	Car() {						//default
		reportingMark = "None";
		carNumber = 0;
		kind = other;
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
		//output();
	}
	// Destructor
	~Car() {};


	// Class specific function
/* ******************** setUpCar ********************
creates an object using a constructor that takes the reference
parameters pointer to the object c1 returned.
*/
	virtual void setUp(string &mark, int &num, string &make, bool &state, string &dest) {
		reportingMark = mark;
		carNumber = num;
		setKind(make);
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

		cout << "\t Kind: \t \t \t" << KIND_ARRAY[kind] << endl;

		if (loaded == true) {
			cout << "\t Loaded: \t \ttrue" << endl;
		}
		else {
			cout << "\t Loaded: \t \tfalse" << endl;
		}

		cout << "\t Destination:\t\t" << destination << endl;
		cout << endl;
	}

	virtual void setKind(string &knd) {
		for (int i = business; i < otherPassenger; i++) {
			if (KIND_ARRAY[i].compare(knd) == 0) {
				kind = static_cast<Kind>(i);
				return;
			}
			else {
				kind = other;
			}
		}
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

class FreightCar : protected Car {
public:
	FreightCar() {						//default
		reportingMark = "None";
		carNumber = 0;
		kind = other;
		loaded = false;
		destination = "None";
	}
	FreightCar(FreightCar &copy) {			//copy
		reportingMark = copy.reportingMark;
		carNumber = copy.carNumber;
		kind = copy.kind;
		loaded = copy.loaded;
		destination = copy.destination;
	}
	FreightCar(string mark, int num, string make, bool state, string dest) {	//unique instance
		setUp(mark, num, make, state, dest);
		//output();
	}
	// Destructor
	~FreightCar() {};

	void setKind(string &knd) {
		for (int i = box; i < otherFreight; i++) {
			if (KIND_ARRAY[i].compare(knd) == 0) {
				kind = static_cast<Kind>(i);
				return;
			}
			else {
				kind = otherFreight;
			}
		}
	}
};

class PassengerCar : protected Car {
public:
	PassengerCar() {						//default
		reportingMark = "None";
		carNumber = 0;
		kind = other;
		loaded = false;
		destination = "None";
	}
	PassengerCar(PassengerCar &copy) {			//copy
		reportingMark = copy.reportingMark;
		carNumber = copy.carNumber;
		kind = copy.kind;
		loaded = copy.loaded;
		destination = copy.destination;
	}
	PassengerCar(string mark, int num, string make, bool state, string dest) {	//unique instance
		setUp(mark, num, make, state, dest);
		//output();
	}
	// Destructor
	~PassengerCar() {};

	void setKind(string &knd) {
		for (int i = chair; i < otherPassenger; i++) {
			if (KIND_ARRAY[i].compare(knd) == 0) {
				kind = static_cast<Kind>(i);
				return;
			}
			else {
				kind = otherPassenger;
			}
		}
	}
};

class StringOfCars {
private:
	Car **carPtr;
	static const int ARRAY_MAX_SIZE = 10;
	int size = 0;
	Car *array[10];
public:

	StringOfCars() {
		size = 0;
		carPtr = new Car*[size];
	}
	
	StringOfCars(StringOfCars &car) {
		carPtr = new Car*[ARRAY_MAX_SIZE];
		for (int i = 0; i < size; i++) {
			carPtr[i] = car.carPtr[i];
		}
	}
	
	~StringOfCars() {
		delete[] carPtr;
	}

	void push(Car &car) {
		if (size >= 10) {
			return;
		}
		array[size] = &car;
		size++;
	};
	/*
	void pop(Car &car) {
		if (size == 0)
			return;
		car = carPtr[size - 1];
		size--;
	}
	*/
	void outputStringofCars() {
		if (size == 0) {
			cout << "NO CARS" << endl;
		}
		else {
			for (int j = 0; j < size; j++) {
				cout << "Car # " << (j + 1) << endl;
				//carPtr = *array[size];
				carPtr[j]->output();
			}
		}
	}
};

void input(StringOfCars &);
Car buildCar(string, int, string, bool, string);
FreightCar buildFreightCar(string, int, string, bool, string);
PassengerCar buildPassengerCar(string, int, string, bool, string);

int main() {
	StringOfCars string1;
	input(string1);
	string1.outputStringofCars();
	StringOfCars string2(string1);
	string2.outputStringofCars();
	system("pause");
	return 0;
}

void input(StringOfCars &str) {
	ifstream inputFile;
	inputFile.open("cardata5.txt");
	if (!inputFile.is_open()) {
		cerr << "File didn't open" << endl;
		return;
	}

	int increment = 0;
	string mark;
	int num;
	string make;
	bool state;
	string dest;

	string temp, temp2 = "     ", temp4;
	string type;
	Car first;
	FreightCar second;
	PassengerCar third;
	Car * ptr;

	while (inputFile.peek() != EOF) {
		increment++;
		inputFile >> type;
		inputFile >> temp4;
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

		cout << temp4 << endl;

		if (type == "Car") {
			first = buildCar(mark, num, make, state, dest);
			ptr = &first;
			str.push(first);
		}
		else if (type == "FreightCar") {
			second = buildFreightCar(mark, num, make, state, dest);

			str.push(second);
		}
		else if (type == "PassengerCar") {
			third = buildPassengerCar(mark, num, make, state, dest);
			//ptr = &third;
			//str.push(ptr);
		}
	}
	inputFile.close();

	return;
}

Car buildCar(string mark, int num, string make, bool state, string dest) {
	carptr = new car;
	carptr -> setup
	Car car(mark, num, make, state, dest);
	car.push();
	//car.output();
	return car;
}
FreightCar buildFreightCar(string mark, int num, string make, bool state, string dest) {
	FreightCar car(mark, num, make, state, dest);
	//car.output();
	return car;
}
PassengerCar buildPassengerCar(string mark, int num, string make, bool state, string dest) {
	PassengerCar car(mark, num, make, state, dest);
	//car.output();
	return car;
}