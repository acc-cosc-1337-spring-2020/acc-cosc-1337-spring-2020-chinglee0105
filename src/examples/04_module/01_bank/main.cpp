#include "checking_account.h"
#include "savings_account.h"
#include "customer.h"
#include "atm.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

using std::cout;
using std::cin;
using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::move;

int main() {
	//bankAccount z; // not allow because it's in stack
	//bankAccount *z; //save memory for an instance of bank account type
	//z = new savingsAccount(60);

	unique_ptr<bankAccount> s = make_unique <savingsAccount> ( 90 ); //heap variable or a pointer behind the scenes
	unique_ptr<bankAccount> c = make_unique <checkingAccount> (100);

	vector<unique_ptr<BankAccount>> accounts;

	accounts.push_back(move(s));
	accounts.push_back(move(c));

	for (auto& account : accounts) {
		cout << account->getBalance() << "\n";
	}

	//for (auto &act : accounts) {
	//	cout << act -> getBalance() << "\n";
	//}

	//bankAccount* act = new checkingAccount(100);
	////use it

	//delete act;
	//act = nullptr;

	//bankAccount a;
	//cout << a.get_balance();

	//vector<bankAccount> accounts{ bankAccount(100), bankAccount(200) };

	//for (auto act : accounts) {
	//	cout << act.get_balance() << "\n";
	//}

	//bankAccount account(500);

	//cin >> account;
	//cout << account;

	//displayBalance(account);

	//auto balance = account.getBalance();
	//cout << "Balance is: \n" << balance;

	//auto amount{ 0 };
	//cout << "\nEnter deposit amount: \n";
	//cin >> amount;

	//try {
	//	account.deposit(amount);
	//	cout << "Balance is: " << account.getBalance();
	//}

	//catch (invalid e) {
	//	cout << e.getError() << "\n";
	//}

	//account.deposit(amount);
	//cout << "Balance is: " << balance;

	return 0;
}