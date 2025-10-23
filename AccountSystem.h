#ifndef ACCOUNTSYSTEM_H
#define ACCOUNTSYSTEM_H

#include "Accounts.h"

class AccountSystem {
private:
    Accounts accts;

public:
    void addAccount();
    void deposit();
    void withdraw();
    void transfer();
    void printAllAccounts();
    bool isEmpty() const;
};

#endif
