//write includes statements
#include<iostream>
#include "loops.h"

//write using statements for cin and cout
using std::cout;
using std::cin;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main() {
	int num;

	cout << "Enter a number: ";
	cin >> num;

	int result;

	result = factorial(num);

	cout << "Result is: " << result;

	return 0;
}