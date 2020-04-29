//
//TODO 7 add template
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <stddef.h>

class Vector {

	public:
		Vector(size_t sz);
		Vector(const Vector& v); //copy constructor - Rule of 3

		Vector& operator=(const Vector& v); //copy assignment - Rule of 3

		Vector(Vector&& v); //move constructor Rule of 5
		Vector& operator=(Vector&& v); //move assignment

		size_t Size() const { return size; }

		int& operator[](int i) { return nums[i]; }
		int& operator[](int i)const { return nums[i]; }

		~Vector(); //destructor - Rule of 3

	private:
		size_t size;
		int* nums;
};

#endif

/*
doesn't belong to class
free function
*/

void useVector();

Vector getVector();