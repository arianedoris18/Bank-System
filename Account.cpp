#include "Account.h"
#include <iostream>
#include <iomanip>

// Default Constructor
Account::Account() {
    accountId = new int(0);
    customerName = "";
    balance = 0.0f;
}

// Copy Constructor
Account::Account(const Account& other) {
    accountId = new int(*other.accountId);
    customerName = other.customerName;
    balance = other.balance;
}

// Copy Assignment
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        *accountId = *other.accountId;
        customerName = other.customerName;
        balance = other.balance;
    }
    return *this;
}

// Destructor
Account::~Account() {
    delete accountId;
    accountId = nullptr;
}

// Mutators / Accessors
void Account::setAccountId(int id) { *accountId = id; }
int Account::getAccountId() const { return *accountId; }

void Account::setCustomerName(const string& name) { customerName = name; }
string Account::getCustomerName() const { return customerName; }

void Account::setBalance(float amount) { balance = amount; }
float Account::getBalance() const { return balance; }

// Deposit
void Account::deposit(float amount) {
   balance += amount;
}

// Withdraw
bool Account::withdraw(float amount) {
    if (balance >= amount){
	balance -= amount;
return true;
}
return false;
}
bool Account::transferTo(Account& dest, float amount){
if (balance < amount )
return false;

balance -= amount;
dest.deposit(amount);
return true;
}

// Print Account Info
void Account::printAccountRow() const {
    cout << "+--------------------------------------------------------+\n";
    cout << "| " << setw(4) << getAccountId() << " | "
         << left << setw(30) << customerName.substr(0, 30) << " | "
         << right << "$" << setw(12) << fixed << setprecision(2) << balance << " |\n";
}
