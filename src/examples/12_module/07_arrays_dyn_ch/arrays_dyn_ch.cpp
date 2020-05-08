#include "arrays_dyn_ch.h"
#include<iostream>

using std::cout;
using std::cin;

//cpp
void dyncamicArray() {
	const int SIZE = 10;
	char* name = new char[SIZE]; //ALLOCATES
	cout << "enter name: ";
	cin.getline(name, SIZE);

	cout << name << "\n";

	delete[] name;
}