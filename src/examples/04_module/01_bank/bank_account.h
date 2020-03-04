#include<string>

//bank_account.h
class bankAccount {
public:
	bankAccount() = default;

	explicit bankAccount(int b) : balance{b}{}

	int get_balance() const { return balance; }

	void deposit(int amount);
	void withdraw(int amount);
	void open(int amount);

private:
	int balance{ 0 };
	const int min_balance_to_open{ 25 };
};

class invalid {
public:
	invalid(std::string msg) : message{msg} {}
	std::string get_error() const { return message; }

private:
	std::string message;
};