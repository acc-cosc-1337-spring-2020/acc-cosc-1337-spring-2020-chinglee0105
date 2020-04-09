#include "atm.h"

//atm.cpp

ostream& operator<<(ostream& out, const ATM& a) {

	out << a.customer;

	return out;
}