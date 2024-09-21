#include <iostream>

using namespace std;

class Account {
    private:
        double balance = 0;

    protected:
        Account(double pBalance) : balance(pBalance) {}

    public:

        void deposit() {
            double deposit;
            bool restart;
            do {
                restart = false;
                system("cls");
                cout << "Your Balance Is: " << getBalance() << endl;
                cout << "Input The Amount You Want To Deposit: ";
                cin >> deposit;

                if (!cin) {
                    system("cls");
                    cout << "Invalid Input!\n";
                    system("pause");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    restart = true;
                }
                else if (deposit < 0) {
                    system("cls");
                    cout << "Please Do Not Input Negative Numbers!\n";
                    system("pause");
                    restart = true;
                }
            } while (restart);
            editBalance(getBalance() + deposit);
            system("cls");
            cout << "You have successfully deposited: " << deposit << endl;
            cout << "Your new balance is: " << getBalance() << endl;
            system("pause");
        }

        virtual void withdraw() = 0;

        virtual void checkBalance() = 0;

        bool showSubMenu() {
            int choice;
            bool restart;
            do {
                restart = true;
                system("cls");
                cout << "Sub Menu\n";
                cout << "1 - Deposit\n";
                cout << "2 - Withdraw\n";
                cout << "3 - Check Balance\n";
                cout << "4- Back\n";
                cin >> choice;

                if (!cin || choice < 1 || choice > 4) {
                    system("cls");
                    cout << "Invalid Input!\n";
                    system("pause");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    restart = true;
                    continue;
                }
                switch(choice) {
                    case 1:
                        deposit();
                        break;
                    case 2:
                        withdraw();
                        break;
                    case 3:
                        checkBalance();
                        break;
                    case 4:
                        return true;
                    default:
                        system("cls");
                        cout << "Please Only Input Between The Given Choice\n";
                        system("pause");
                        restart = true;
                        break;
                }
            } while (restart);
            return false;
        }

        double getBalance() { return balance;}

        void editBalance(double newBalance) {this->balance = newBalance;} 
};

class SavingsAccount : public Account {
    public:
        SavingsAccount(double pBalance) : Account(pBalance) {}

        void withdraw() override {
            if (getBalance() <= 1000) {
                system("cls");
                cout << "Your Balance Is: " << getBalance() << endl;
                cout << "You Cannot Withdraw! The Minimum Balance For Savings Account is 1000!\n";
                system("pause");
                return;
            }
            double withdraw;
            bool restart;
            do {
                restart = false;
                system("cls");
                cout << "Your Balance Is: " << getBalance() << endl;
                cout << "Input The Amount You Want To Withdraw: ";
                cin >> withdraw;

                if (!cin) {
                    system("cls");
                    cout << "Invalid Input!\n";
                    system("pause");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    restart = true;
                }
                else if (withdraw < 0) {
                    system("cls");
                    cout << "Please Do Not Input Negative Numbers!\n";
                    system("pause");
                    restart = true;
                }
                else if (getBalance() - withdraw < 1000) {
                    system("cls");
                    cout << "You Cannot Withdraw " << withdraw <<"! The Minimum Balance For Savings Account is 1000!\n";
                    system("pause");
                    restart = true;
                }
                else if (getBalance() < withdraw) {
                    system("cls");
                    cout << "Invalid Input! Your Balance Is Less Than "<< withdraw <<"!\n";
                    system("pause");
                    restart = true;
                }
            } while (restart);
            editBalance(getBalance() - withdraw);
            system("cls");
            cout << "You have successfully withdrew: " << withdraw << endl;
            cout << "Your new balance is: " << getBalance() << endl;
            system("pause");
            
        }

        void checkBalance() override {
            system("cls");
            cout << "The Balance Of Your Savings Account Is: " << getBalance() << endl;
            system("pause");
        }
};

class CurrentAccount : public Account {
    private:
    public:
        CurrentAccount(double pBalance) : Account(pBalance) {}

        void withdraw() override {
            if (getBalance() <= 0) {
                system("cls");
                cout << "Your Balance Is: " << getBalance() << endl;
                cout << "You Cannot Withdraw!\n";
                system("pause");
                return;
            }
            double withdraw;
            bool restart;
            do {
                restart = false;
                system("cls");
                cout << "Your Balance Is: " << getBalance() << endl;
                cout << "Input The Amount You Want To Withdraw: ";
                cin >> withdraw;

                if (!cin) {
                    system("cls");
                    cout << "Invalid Input!\n";
                    system("pause");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    restart = true;
                }
                else if (withdraw < 0) {
                    system("cls");
                    cout << "Please Do Not Input Negative Numbers!\n";
                    system("pause");
                    restart = true;
                }
                else if (getBalance() < withdraw) {
                    system("cls");
                    cout << "Invalid Input! Your Balance Is Less Than "<< withdraw <<"!\n";
                    system("pause");
                    restart = true;
                }
            } while (restart);
            editBalance(getBalance() - withdraw);
            system("cls");
            cout << "You have successfully withdrew: " << withdraw << endl;
            cout << "Your new balance is: " << getBalance() << endl;
            system("pause");
        }

        void checkBalance() override {
            system("cls");
            cout << "The Balance Of Your Current Account Is: " << getBalance() << endl;
            system("pause");
        }
};

int main() {
    int choice;
    bool restart;
    SavingsAccount savingsAcc(1000);
    CurrentAccount currentAcc(0);
    do {
        restart = false;
        system("cls");
        cout << "Main Menu\n";
        cout << "1 - Savings Account\n";
        cout << "2 - Current Account\n";
        cout << "3 - Exit\n";
        cin >> choice;

        if (!cin || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(1000, '\n');
            system("cls");
            cout << "Invalid Input!\n";
            system("pause");
            restart = true;
            continue;
        }

        switch (choice) {
            case 1:
                if (savingsAcc.showSubMenu()) {
                    restart = true;
                    continue;
                }
                break;
            case 2:
                if (currentAcc.showSubMenu()) {
                    restart = true;
                    continue;
                }
                break;
            case 3:
                return 0;
            default:
                system("cls");
                cout << "Please Only Input Between The Given Choices\n";
                system("pause");
                restart = true;
                break;
        }
    } while (restart);
    return 0;
}