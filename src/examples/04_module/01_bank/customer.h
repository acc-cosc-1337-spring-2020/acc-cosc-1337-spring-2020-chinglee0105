#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "bank_account.h"
#include <memory>
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::cin;
using std::unique_ptr;

//customer.h
class customer {

	public:
		void addAccount(unique_ptr<bankAccount>& act);
		friend ostream& operator<<(ostream& out, const customer& c);

	private:
		vector<unique_ptr<bankAccount>> accounts;
};

#endif //!CUSTOMER_H