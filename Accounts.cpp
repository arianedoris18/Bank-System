#include "Accounts.h"
#include <iostream>
#include <iomanip>

using namespace std;

Accounts::Accounts() {
    list = new Account[MAX_SIZE];
    size = 0;
}

Accounts::~Accounts() {
    delete[] list;
    size = 0;
}

void Accounts::addAccount(Account& acc) {
    if (size >= MAX_SIZE) {
        cout << "Error: account list is full.\n";
        return;
    }

    if (find(acc.getAccountId()) != -1) {
        cout << "Error: account id " << acc.getAccountId() << " already exists.\n";
        return;
    }

    list[size] = acc;
    size++;

    cout << "Added new account id " << acc.getAccountId()
         << " with initial balance $" << fixed << setprecision(2)
         << acc.getBalance() << endl;
}

int Accounts::find(int id) const {
    for (int i = 0; i < size; i++) {
        if (list[i].getAccountId() == id)
            return i;
    }
    return -1;
}

Account& Accounts::at(int index) const {
    return list[index];
}
