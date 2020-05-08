#include "arrays_char.h"
#include <iostream>

using std::cout;

//cpp
void charArray() {
	const int SIZE = 5;
	char name[SIZE] = "Mary";
	name[4] = '\0';

	cout << name << "\n\n";

	for (inti = 0; name[i] != '\0'; ++i) {
		cout << name[i] << "\n";
	}
}

void charArrayNoSize() {
	char name[] = "Mary";
	cout << name << "\n\n";
}