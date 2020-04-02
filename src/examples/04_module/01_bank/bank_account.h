#include<string>
#include<iostream>

#ifndef BANK_ACCOUNT_H //header guards
#define BANK_ACCOUNT_H

using std::string;
using std::ostream;
using std::istream;

//bank_account.h
class bankAccount {
public:
	bankAccount() = default;

	explicit bankAccount(int b) : balance{b}{}

	virtual int get_balance() const { return balance; }

	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);

	double get_rate() const { return rate; }

	friend void display_balance(const bankAccount& b);
	friend ostream& operator<<(ostream& out, const bankAccount& b);
	friend istream& operator>>(istream& in, bankAccount& b);

protected:
	int balance{ 0 };

private:
	const int min_balance_to_open{ 25 };

	static double rate;
	static double init_rate() { return .025; }
};

#endif

#ifndef INVALID_H
#define INVALID_H

class invalid {
public:
	invalid(string msg) : message{msg} {}
	string get_error() const { return message; }

private:
	string message;
};

#endif