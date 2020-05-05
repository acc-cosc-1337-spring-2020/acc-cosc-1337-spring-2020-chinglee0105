//
//TODO 7 add template
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <stddef.h>

class Vector {

	public:
		Vector();
		Vector(size_t sz);
		Vector(const Vector& v); //copy constructor - Rule of 3

		Vector& operator=(const Vector& v); //copy assignment - Rule of 3

		Vector(Vector&& v); //move constructor Rule of 5
		Vector& operator=(Vector&& v); //move assignment

		size_t Size() const { return size; }

		int& operator[](int i) { return nums[i]; }
		int& operator[](int i)const { return nums[i]; }

		void Reserve(size_t new_allocation);

		size_t Capacity()const{ return space; }

		void Resize(size_t mew_size);
		void Push_Back(int value);
		
		~Vector(); //destructor - Rule of 3

	private:
		size_t size;
		size_t space{ 0 };
		int* nums;
		const int RESERVE_DEFAULT_SIZE{ 8 };
		const int RESERVE_DEFAULT_MULTIPLIER{ 2 };
};

#endif

/*
doesn't belong to class
free function
*/

void useVector();

Vector getVector();