#include "bank_account.h"

//bank_account.cpp

void bankAccount::deposit(int amount) {
	if (amount > 0) {
		balance += amount;
	}
	else {
		throw invalid("Amount must be greater than 0.");
	}
}

void bankAccount::withdraw(int amount) {
	if (amount < 0) {
		throw invalid("Amount must be greater than 0.");
	}
	else if (amount > balance) {
		throw invalid("Insufficient Funds.");
	}
	else {
		balance -= amount;
	}
}