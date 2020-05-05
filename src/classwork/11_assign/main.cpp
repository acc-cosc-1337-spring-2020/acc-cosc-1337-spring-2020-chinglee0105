#include "vector.h"
#include<iostream>

int main() {
	////lvalue-can reference or has an address is accessible
	//int num = 5; //5 is an rvalue
	//int& num_ref = num; //right here accessible
	////rvalue
	//int&& num_5 = 5;
	//int a = 1, b = 5, c;
	//c = a * b; //a*b is an rvalue

	//Vector v1 = getVector();
	Vector v;

	Vector v1(3);
	v1 = getVector();

	return 0;
}