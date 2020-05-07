#include "arrays_mem.h"
#include <iostream>

using std::cout;
//write code for for stack_array and display each element to screen

void stackArray() {
	const int SIZE = 5;
	int hours[SIZE];

	for (int i = 0; i < SIZE; i++) {
		hour[i] = i * 10;
	}

	for (int i = 0; i < SIZE; i++) {
		cout << hours[i] << "\n";
	}
}

void stackArrayInit() {
	cout << "\n";
	const int SIZE = 5;
	int hours[SIZE] = { 0,10,20,30,40 };

	for (int i = 0; i < SIZE; i++) {
		cout << hours[i] << "\n";
	}
}

void stackArrayInitForRanged() {
	cout << "\n";
	const int SIZE = 5;
	int hours[SIZE] = { 0,10,20,30,40 };

	for (auto hour: hours {
		cout << hour << "\n";
	}
}