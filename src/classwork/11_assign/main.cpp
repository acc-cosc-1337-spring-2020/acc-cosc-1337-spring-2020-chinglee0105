#include "vector.h"
#include <iostream>

using std::cout;

int main() {	
	Vector<int> v1(3);
	
	for (size_t i = 0; i < v1.Size(); ++i) {
		cout << v1[i] << "\n";
	}

	return 0;
}