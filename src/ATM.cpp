#include <iostream>
#include <math.h>

struct Name {
    std::string first;
    std::string last;
};

class ATM {
    private:
        double balance;
        int mobileNumber;
        Name name;
        std::string birthday;
        std::string dateOpened;
    public:
        void setBalance() {
            balance = 0.00;
        }
        void setName(std::string first, std::string last) {
            name.first = first;
            name.last = last;
        }
        void setMobileNumber(int num) {
            mobileNumber = num;
        }
        void withdraw(int amount) {
            if (amount > balance) {
                std::cout << "Current balance is too low for this withdrawal." << "\n";
            } else if (amount <= balance) {
                balance -= amount;
                std::cout << "Withdrawal successful." << "\n";
            }
        }
        void deposit(int money) {
            int type;
            std::cout << "Are you implementing cash or check deposit? Insert 1 for cash and 2 for check " << "\n";
            std::cin >> type;

            if (money <= 0) {
                std::cout << "Deposit must be a positive number!!" << "\n";
            } else if (money > 0) {
                if (type == 1) {
                    balance += money;
                    std::cout << money << " has successfully been deposited into your account." << "\n";
                } else if (type == 2) {
                    balance += money;
                    std::cout << "Please wait for one business day for the money to appear in your account." << "\n";
                }
            }
        }
        void updateMobileNumber(int newNumber) {
            // for now, numbers must have just 10 digits!
            if (newNumber <= 0 || (trunc(log10(newNumber)) + 1) < 10) {
                std::cout << "Please insert the right 10-digit number" << "\n";
            } else {
                mobileNumber = newNumber;
            }
        }

};