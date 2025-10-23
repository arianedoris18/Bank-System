#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
using namespace std;
class Account{
public:
Account();
Account(const Account& other);
~Account();
Account& operator=(const Account& other);
void setAccountId(int id);
int getAccountId() const;
void setCustomerName(const string& name);
string getCustomerName() const;
void setBalance(float amount);
float getBalance() const;
  void deposit(float amount);
    bool withdraw(float amount);
 bool transferTo(Account& dest, float amount);
 void printAccountRow() const;
private:
int* accountId;
string customerName;
float balance;
};
#endif

