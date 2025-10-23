#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include "Account.h"

class Accounts {
private:
    const int MAX_SIZE = 1000;
    Account* list;
    int size;

public:
    Accounts();
    ~Accounts();

    int getSize() const { return size; }
    void addAccount(Account& acc);
    int find(int id) const;
    Account& at(int index) const;
};

#endif
