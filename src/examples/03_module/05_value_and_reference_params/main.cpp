#include<iostream>

using std::cout;

int mian() {
	int num = 5;
	cout << "Valuse of num is: " << num << " Address is " << &num;

	int &num_ref = num;
	num_ref = 10;
	cout << "\nValuse of num is: " << num << " Address is " << &num;

	return 0;
}