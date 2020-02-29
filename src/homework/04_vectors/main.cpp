#include"vectors.h"
#include <vector>
#include <iostream>
#include<string>

using std::cout;
using std::cin;
using std::vector;
using std::string;

/*
use a vector of int with values 8, 4, 20, 88, 66, 99

Prompt user for 1 for Get Max from vector and 2 for Get primes.
Prompt user for a number and return max value or list of primes
and display them to screen.
Program continues until user decides to exit.

*/

int main() {
	bool proceed = true;
	bool errorOccured = false;

	int prompt;
	int numChoice;
	string decisionToProceed;

	vector<int> num{ 8, 4, 20, 88, 66, 99 };

	while (proceed) {
		if (errorOccured == false) {
			cout << "Enter 1 to get max from vector, 2 to get primes: ";
			cin >> prompt;
		}

		if (prompt == 1) {
			cout << get_max_from_vector(num);
		}

		else if (prompt == 2) {
			cout << "Enter a number: ";
			cin >> numChoice;
			vector<int> all = vector_of_primes(numChoice);

			for (auto x : all) {
				cout << x;
			}
		}

		else {
			cout << "Error! Please enter 1 to get max from vector or 2 to get primes: ";
			cin >> prompt;
			errorOccured = true;
			continue;
		}

		cout << "Do you wish to continue? (Y/N): ";
		cin >> decisionToProceed;

		if (decisionToProceed != "y" && decisionToProceed != "Y") {
			proceed = false;
		}
	}	
	
	cout << "End of program.";
}