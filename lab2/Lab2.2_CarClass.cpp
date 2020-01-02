#/*
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
		Car ()	{
			reportingMark = "None";
			carNumber = 0;
			kind = "None";
			loaded = false;
			destination = "None";
		}
		Car(string mark, int num, string make, bool state, string dest)	{
			reportingMark = mark;
			carNumber = num;
			kind = make;
			loaded = state;
			destination = dest;
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
		*/ 
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
		

		// Class specific function
	/* ******************** setUpCar ********************
	creates an object using a constructor that takes the reference 
	parameters pointer to the object c1 returned.
	*/
		Car* setUpCar(string mark, int num, string make, bool state, string dest)
		{
			Car *c1 = new Car(mark, num, make, state, dest);
			return c1;
		}; // end setUpCar
};

void input(string &mark, int &num, string &make, bool &state, string &dest);
void output(Car *ptr);

int main() {
	string mark, make, dest;
	int num;
	bool state;

	input(mark, num, make, state, dest);
	Car sophia; // <3
	Car *cPtr;
	cPtr = &sophia;

	sophia = *cPtr-> setUpCar(mark, num, make, state, dest);
	output(cPtr);
	sophia.~Car();
	cPtr = NULL;
	system("pause");
	return 0;
}

void input(string &mark, int &num, string &make, bool &state, string &dest) {
	string temp, temp2 = "ouuuu";

	cout << "Insert reporting mark (string of 5 or less upper case characters)" << endl;
	cin >> mark;
	int inputSize = 5, index = 0;	// initialize size and increment variables
	while (index != inputSize) {
		if (mark[index] >= 97 && mark[index] <= 122) {
			temp2[index] = mark[index] - 32;
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

void output(Car *ptr) {
	cout << endl;
	cout << "************************************" << endl;
	cout << "------------Car Data----------------" << endl;
	cout << "************************************" << endl;

	
	cout << "Reporting mark: \t" << ptr-> getReportingMark() << endl;

	cout << "Car number: \t \t" << ptr-> getCarNumber() << endl;

	cout << "Kind: \t \t \t" << ptr-> getKind() << endl;

	//cout << "Loaded: " << ptr-> getLoaded() << endl;
	if (ptr->getLoaded() == true) {
		cout << "Loaded: \t \ttrue" << endl;
	}
	else {
		cout << "Loaded: \t \t false" << endl;
	}

	cout << "Destination: \t \t" << ptr-> getDestination() << endl;
	
}



