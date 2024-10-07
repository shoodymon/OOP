#pragma once

#include "includes.hpp"

class Bank {
private:
	std::string m_accountNumber;
	double m_balance;

public:
	Bank(const std::string& accountNumber, double balance) 
		: m_accountNumber(accountNumber), m_balance(balance) {}

	std::string getAccountNumber() const { return m_accountNumber; }
	void setAccountNumber(const std::string& accountNumber) { m_accountNumber = accountNumber; }

	double getBalance() const { return m_balance; }
	void setBalance(double balance) { m_balance = balance; }

	bool withdraw(double amount) {
		if (m_balance >= amount) {
			m_balance -= amount;
			return true;
		}
		return false;
	}
};