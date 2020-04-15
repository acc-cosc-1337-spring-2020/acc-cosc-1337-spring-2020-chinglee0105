//savings_account.h
#include "bank_account.h"

class savingsAccount : public bankAccount {
public:
	savingsAccount() = default;
	explicit savingsAccount(int b) : bankAccount(b) {}

	int getBalance() const { return 5000; }
};