#include "vector.h"
#include <iostream>

using std::cout;

/*
Initialize nums to size dynamic array.
Initialize each array element to 0.
*/
Vector::Vector(size_t sz)
    : size{ sz }, nums{new int[sz]} {

    for (size_t i = 0; i < sz; ++i) {
        nums[i] = 0;
    }
}



/*
Copy v.size to new class
Create new dynamic memory
Initialize array elements to the v.nums array values
*/
Vector::Vector(const Vector& v)
    : size{ v.size }, nums{ new int[v.size] } {

    for (size_t i = 0; i < size; ++i) {
        nums[i] = v[i];
    }
}


/*
Release dynamic memory
Deallocate memory
*/
Vector::~Vector() {
    cout << "\n release memory \n";
    delete[] nums;
}


//===============================
//Free function
void useVector() {
    Vector* v1 = new Vector(3);
    delete v1;
}