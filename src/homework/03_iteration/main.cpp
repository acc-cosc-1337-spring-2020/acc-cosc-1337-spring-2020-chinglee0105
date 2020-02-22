//write include statements
#include<iostream>
#include<string>
#include "dna.h"

//write using statements
using std::cout;
using std::cin;
using std::string;


/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() {
	int choice;

	string dna;
	string result;
	string decisionToProceed;

	bool proceed = true;
	bool errorOccured = false;

	while (proceed) {

		if (errorOccured == false) {
			cout << "Enter 1 for Get GC Content or 2 for Get DNA Complement: ";
			cin >> choice;
		}

		cout << "Enter your DNA: ";
		cin >> dna;

		if (choice == 1) {
			cout << get_gc_content(dna);
		}

		else if (choice == 2) {
			cout << get_dna_complement(dna);
		}

		else {
			cout << "Error! Please enter 1 for Get GC Content or 2 for Get DNA Complement: ";
			cin >> choice;
			errorOccured = true;
			continue;
		}

		cout << "Do you wish to continue? (Y/y): ";
		cin >> decisionToProceed;

		if (decisionToProceed != "y" && decisionToProceed != "Y") {
			proceed = false;
		}
	}

	cout << "End of program.";
}