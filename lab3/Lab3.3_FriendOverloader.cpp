/*
Iraj Shrotri
Summer 2019
Lab 2
Problem 2.2

*/

#include <iostream>
#include <string>

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

void input(string &mark, int &num, string &make, bool &state, string &dest);

int main() {
	string mark, make, dest;
	int num;
	bool state;
	//Car car2, car3;
	input(mark, num, make, state, dest);

	Car car1(mark, num, make, state, dest);
	Car car2(car1);
	Car car3;

	cout << "Contents of car1:";
	car1.output();

	cout << "Contents of car2:";
	car2.output();

	cout << "Contents of car3:";
	car3.output();

	//car1.~Car();
	system("pause");

	if (car1 == car2)
		cout << "car1 is the same car as car2\n";
	else
		cout << "car1 is not the same car as car2\n";
	if (car2 == car3)
		cout << "car2 is the same car as car3\n";
	else
		cout << "car2 is not the same car as car3\n";

	system("pause");

	return 0;
}

void input(string &mark, int &num, string &make, bool &state, string &dest) {
	string temp, temp2 = "     ";

	cout << "Insert reporting mark (string of 5 or less upper case characters)" << endl;
	getline(cin, mark);
	//cout << mark;
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
	//ptr->reportingMark = temp2;

	cout << "Insert car number (int)" << endl;
	cin >> num;

	cout << "Insert kind (box, tank, flat, or other)" << endl;
	cin >> make;

	//cout << "Insert loaded (T/F)" << endl;
	//cin >> state;
	cout << "Insert loaded (true/false)" << endl;
	cin >> temp;
	if (temp == "true") {
		state = true;
	}
	else {
		state = false;
	}

	cout << "Insert destination (string with a destination or the word NONE)" << endl;
	cin >> dest;

	return;
}

