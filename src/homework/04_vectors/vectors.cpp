#include"vectors.h"
#include<vector>
#include <iostream>
using std::vector;

/*
Write a value return function get_max_from_vector with a const reference 
vector of intsparameter that returns the max value in a vector

@param numbers is a const reference to a vector of integers
@return the max value in the vector
*/
int get_max_from_vector(const std::vector<int>& num) {
	int max = 0;
	for (auto x : num) {
		if (x > max) {
			max = x;
		}
	}

	return max;
}


/*
Write a function named is_prime with an integer parameter that
given a number returns true if prime or false if not prime

@param number: Any whole number
@return: bool if prime False if not
*/
bool is_prime(int num) {
	if (num <= 1) {
		return false;
	}

	for (int i = 2; i < num; ++i) {
		if (num % i == 0) {
			return false;
		}
	 }

	return true;
}


/*
Write a a function named vector_of_primes with an integer parameter
that given a number returns all the prime numbers up to the number

Example given number 10 returns a vector with elements 2,3,5,7,

@param int integer value
@return vector of ints containing prime values up to a value

Make sure to use the is_prime function to determine if current 
number is prime.
*/
vector<int> vector_of_primes(int num) {
	vector<int> all;
	for (int i = 2; i < num; ++i) {
		if (is_prime(i) == true)
			all.push_back(i);
	}

	return all;
}
