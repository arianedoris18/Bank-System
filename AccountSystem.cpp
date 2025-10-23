#include "AccountSystem.h"
#include <iostream>
#include <iomanip>
using namespace std;

bool AccountSystem::isEmpty() const {
    return accts.getSize() == 0;
}

void AccountSystem::addAccount() {
    int id;
    string name;
    float initialDeposit;

    cout << "Enter account id: ";
    cin >> id;
    cin.ignore();

    // Check if already exists
    if (accts.find(id) != -1) {
        cout << "Error: account id " << id << " already exists.\n";
        return;
    }

    cout << "Enter customer account name: ";
    getline(cin, name);

    cout << "Enter initial deposit amount: $ ";
    cin >> initialDeposit;

    Account acc;
    acc.setAccountId(id);
    acc.setCustomerName(name);
    acc.setBalance(initialDeposit);
    accts.addAccount(acc);
}

void AccountSystem::deposit() {
    if (isEmpty()) {
        cout << "Empty account list.\n";
        return;
    }

    int id;
    cout << "Enter account id: ";
    cin >> id;

    int index = accts.find(id);
    if (index == -1) {
        cout << "Error: account with id " << id << " not found.\n";
        return;
    }

    float amount;
    cout << "Enter the deposit amount: $ ";
    cin >> amount;

    accts.at(index).deposit(amount);
    cout << "Deposited $" << fixed << setprecision(2) << amount
         << " into account id " << id << endl;
}

void AccountSystem::withdraw() {
    if (isEmpty()) {
        cout << "Empty account list.\n";
        return;
    }

    int id;
    cout << "Enter account id: ";
    cin >> id;

    int index = accts.find(id);
    if (index == -1) {
        cout << "Error: account with id " << id << " not found.\n";
        return;
    }

    float amount;
    cout << "Enter the withdraw amount: $ ";
    cin >> amount;

    if (accts.at(index).withdraw(amount)) {
        cout << "Withdrawn $" << fixed << setprecision(2)
             << amount << " from account id " << id << endl;
    } else {
        cout << "Error: failed to withdraw $" << fixed << setprecision(2)
             << amount << " from account id " << id << endl;
    }
}

void AccountSystem::transfer() {
    if (isEmpty()) {
        cout << "Empty account list.\n";
        return;
    }

    int srcID, destID;
    cout << "Enter source account id: ";
    cin >> srcID;
    cout << "Enter destination account id: ";
    cin >> destID;

    int srcIndex = accts.find(srcID);
    int destIndex = accts.find(destID);

    if (srcIndex == -1 || destIndex == -1) {
        cout << "Error: Source or destination account number not found. Operation failed.\n";
        return;
    }

    float amount;
    cout << "Enter the transfer amount: $ ";
    cin >> amount;

    Account& src = accts.at(srcIndex);
    Account& dest = accts.at(destIndex);

    if (src.getBalance() < amount) {
        cout << "Error: Insufficient balance. Source account has only $"
             << fixed << setprecision(2) << src.getBalance()
             << " in the balance.\n";
        return;
    }

    src.transferTo(dest, amount);
    cout << "Successfully transferred amount $" << fixed << setprecision(2)
         << amount << " from source account id " << srcID
         << " to destination account id " << destID << endl;
}

void AccountSystem::printAllAccounts() {
    if (isEmpty()) {
        cout << "Empty account list.\n";
        return;
    }

    cout << "+--------------------------------------------------------+\n";
    cout << "| Acct | Customer Account Name          | Balance        |\n";
    for (int i = 0; i < accts.getSize(); i++) {
        accts.at(i).printAccountRow();
    }
    cout << "+--------------------------------------------------------+\n";
}

