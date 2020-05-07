#include "arrays_pointers.h"
#include <iostream>

using std::cout;
//cpp
void arrayPointer() {
	const int SIZE = 5;

	int hours[SIZE] = { 0,10,20,30,40 };
	int* hours_ptr = hours;

	cout << *hours_ptr << "\n";
	*hours_ptr++;

	cout << *hours_ptr++ << "\n";
	*hours_ptr--;

	cout << *hours_ptr++ << "\n";
}

void arrayPointerLoop() {
	const int SIZE = 5;

	int hours[SIZE] = { 0,10,20,30,40 };
	int* hours_ptr = hours;

	for (int = 0; i < SIZE; ++i) {
		cout << *hours_ptr << "\n";
		*hours_ptr++;
	}

	cout << "\n";

	for (inti = 0; i < SIZE; ++i) {
		*hours_ptr--;
		cout << *hours_ptr << "\n";
	}
}