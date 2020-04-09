#ifndef ATM_H
#define ATM_H

#include "customer.h"

using std::move;

//atm.h
class ATM {

public:

	ATM(customer& c) : customer(move(c)) {}
	friend ostream& operator<<(ostream& out, const ATM& a);

private:

	customer customer;
};
#endif