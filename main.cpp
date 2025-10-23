#include "AccountSystem.h"
#include <iostream>
using namespace std;

void printBanner() {
    cout << "+------------------------------------------------------+\n";
    cout << "|       Computer Science and Engineering               |\n";
    cout << "|      CSCE 1040 - Computer Science II                 |\n";
    cout << "|   Ariane Doris Umuhire au0177 dorisumuhire@my.unt.edu|\n";
    cout << "+------------------------------------------------------+\n\n"; 
}

void printMenu() {
    cout << "+--------------------------------------+\n";
    cout << "| Enter account selection              |\n";
    cout << "| 1 : Add new account                  |\n";
    cout << "| 2 : Deposit into account             |\n";
    cout << "| 3 : Withdraw from account            |\n";
    cout << "| 4 : Transfer into account            |\n";
    cout << "| 5 : Print a list of all accounts     |\n";
    cout << "| 6 : End transaction (Exit)           |\n";
    cout << "+--------------------------------------+\n";
    cout << "> ";
}

int main() {
    printBanner();

    AccountSystem system;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1: system.addAccount(); break;
            case 2: system.deposit(); break;
            case 3: system.withdraw(); break;
            case 4: system.transfer(); break;
            case 5: system.printAllAccounts(); break;
            case 6:
                cout << "Thank you for running the program. Goodbye!\n";
                break;
            default:
                cout << "Error: Invalid selection. Enter a value between 1-6.\n";
        }
        cout << endl;
    } while (choice != 6);

    return 0;
}
