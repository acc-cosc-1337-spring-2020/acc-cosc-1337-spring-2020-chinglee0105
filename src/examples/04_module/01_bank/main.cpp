#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cout;
using std::cin;
using std::vector;
using std::unique_ptr;
using std::make_unique;

int main() {
	unique_ptr<bankAccount> s = make_unique < savingsAccount> ( 90 );
	unique_ptr<bankAccount> c = make_unique < checkingAccount> (100);

	vector<unique_ptr<bankAccount>> accounts;
	accounts.push_back(std::move(s));
	accounts.push_back(std::move(c));

	for (auto &act : accounts) {
		cout << act->getBalance() << "\n";
	}

	bankAccount* act = new checkingAccount(100);
	//use it

	delete act;
	act = nullptr;

	/*

	do you want to play again loop
	TTT game;

	loop for mark board

	game ends

	call manager save game
	*/

	//bankAccount a;
	//cout << a.get_balance();

	//vector<bankAccount> accounts{ bankAccount(100), bankAccount(200) };

	//for (auto act : accounts) {
	//	cout << act.get_balance() << "\n";
	//}

	bankAccount account(500);

	cin >> account;
	cout << account;

	displayBalance(account);

	auto balance = account.getBalance();
	cout << "Balance is: \n" << balance;

	auto amount{ 0 };
	cout << "\nEnter deposit amount: \n";
	cin >> amount;

	try {
		account.deposit(amount);
		cout << "Balance is: " << account.getBalance();
	}

	catch (invalid e) {
		cout << e.getError() << "\n";
	}

	account.deposit(amount);
	cout << "Balance is: " << balance;

	return 0;
}