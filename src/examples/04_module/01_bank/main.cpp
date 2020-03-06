#include"bank_account.h"
#include<iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int main() {
	bankAccount a;
	cout << a.get_balance();

	vector<bankAccount> accounts{ bankAccount(100), bankAccount(200) };

	for (auto act : accounts) {
		cout << act.get_balance() << "\n";
	}

	bankAccount account(500);

	cin >> account;
	cout << account;

	display_balance(account);

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