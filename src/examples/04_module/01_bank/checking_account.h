//checking_account.h
#include "bank_account.h"

class checkingAccount : public bankAccount {
	public:
		checkingAccount() = default;
		explicit checkingAccount(int b) : bankAccount(b){}
		int getBalance()const { return balance * (1 + get_rate()); }
};