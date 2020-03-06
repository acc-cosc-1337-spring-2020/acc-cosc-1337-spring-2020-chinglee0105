#include "bank_account.h"
#include<iostream>

using std::cout;

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

void bankAccount::open(int amount) {
	if (amount < min_balance_to_open) {
		throw invalid("Amount must be at least 25...");
	}
	
	balance += amount;
}

double bankAccount::rate = init_rate();

void display_balance(const bankAccount& b) {
	cout << "Balance is: " << b.balance << "\n";
}

ostream& operator<<(ostream& out, const bankAccount& b) {
	out << "Balance is: " << b.balance << "\n";
	return out;
}

istream& operator>>(istream& in, bankAccount& b) {
	int amount;

	cout << "Enter amount: ";
	in >> amount;

	b.deposit(amount);

	return in;
}
