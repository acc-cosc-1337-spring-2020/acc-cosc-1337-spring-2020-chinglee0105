#include"bank_account.h"
#include<iostream>

using std::cout;
using std::cin;

int main() {
	bankAccount account(500);

	auto balance = account.get_balance();
	cout << "Balance is: \n" << balance;

	auto amount{ 0 };
	cout << "\nEnter deposit amount: \n";
	cin >> amount;

	try {
		account.deposit(amount);
		cout << "Balance is: " << account.get_balance();
	}

	catch (invalid e) {
		cout << e.get_error() << "\n";
	}

	account.deposit(amount);
	cout << "Balance is: " << balance;

	return 0;
}