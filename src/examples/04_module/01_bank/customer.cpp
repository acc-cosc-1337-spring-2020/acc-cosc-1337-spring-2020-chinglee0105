#include"customer.h"
//customer.cpp

void customer::addAccount(unique_ptr<bankAccount>& act) {

	accounts.push_back(move(act));
}

ostream& operator<<(ostream& out, const customer& c) {

	for (auto& account : c.accounts) {
		out << *account<< "\n";
	}

	return out;
}
