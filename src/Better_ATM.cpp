#include <curses.h>
#include <iostream>
#include <string>

// TODO -> Code is not working right now because there is no way to get the terminal to pauce like getch()
// TODO: -> The conio.h library is dead, and we are adviced not to use it. But the general concept of the code works

class Atm {
    private:
        long int account_no;
        std::string name;
        int PIN;
        double balance;
        std::string mobile_No;

    public:
        void setData(long int account_no_a, std::string name_a, int PIN_a, double balance_a, std::string mobile_No_a) {
            account_no = account_no_a;
            name = name_a;
            PIN = PIN_a;
            balance = balance_a;
            mobile_No = mobile_No_a;
        }

        // return user's account number
        long int getAccountNo() {
            return account_no;
        }

        std::string getName() {
            return name;
        }

        int getPin() {
            return PIN;
        }

        double getBalance() {
            return balance;
        }

        std::string getMobileNo() {
            return mobile_No;
        }

        // update the users moble number
        void setMobile(std::string mobile_prev, std::string mob_new) {
            if (mobile_prev == mobile_No) {
                mobile_No = mob_new;
                std::cout << "Successfully updated your mobile number." << "\n";
                //;     // hold the screen till user enters a number;

            }
        }

        void cashWithdraw(int amount_a) {
            if (amount_a > 0 && amount_a < balance) {
                balance -= amount_a;
                std::cout << "Please collect your cash." << "\n";
                std::cout << "Available balance: " << balance << "\n";
                //;
            } else {
                std::cout << "Invalid input or insufficient balance " << "\n";
                //;
            }
        }
};

int main() {
    int choice = 0, enterPin;
    long int enterAccountNo;

    system("clear"); // clear the screen automatically

    Atm user1;

    user1.setData(1234567, "Emeka", 1111, 100000, "9992220932");

    do {
        system("clear");

        std::cout << "*****Welcome to ATM*****" << "\n";
        std::cout << "Enter your account number ";
        std::cin >> enterAccountNo;

        std::cout << "\n" << "Enter PIN ";
        std::cin >> enterPin;

        // perform validation
        if ((enterAccountNo == user1.getAccountNo()) && (enterPin == user1.getPin())) {
            do {
                int amount = 0;
                std::string oldMobileNo, newMobileNo;

                system("clear");
                // user interface
                std::cout << "\n" << "*****Welcome to ATM*****" << "\n";
                std::cout << "Select options " << "\n";
                std::cout << "1. Check Balance " << "\n";
                std::cout << "2. Cash Withdrawal " << "\n";
                std::cout << "3. Show User Details " << "\n";
                std::cout << "4. Update Mobile Number " << "\n";
                std::cout << "5. Exit " << "\n";
                std::cin >> choice;

                switch (choice) {
                    case 1:
                        std::cout << "Your account balance is " << user1.getBalance() << "\n";
                        //;
                        break;

                    case 2:
                        std::cout << "Enter the amount: ";
                        std::cin >> amount;
                        user1.cashWithdraw(amount);

                        break;

                    case 3:
                        std::cout <<"*** User Details are :- ";
                        std::cout << "-> Account no" << user1.getAccountNo();
                        std::cout << "-> Name      " << user1.getName();
                        std::cout << "-> Balance   " << user1.getBalance();
                        std::cout << "-> Mobile No." << user1.getMobileNo();
                        // getting and printing user details
                        //;
                        break;

                    case 4:
                        std::cout << "Enter old moble num ";
                        std::cin >> oldMobileNo;

                        std::cout << "\n" << "Enter new mobile num ";
                        std::cin >> newMobileNo;

                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;
                    
                    case 5:
                        exit(0);

                    default:
                        std::cout << "Enter valid data! " << "\n";
                } 
            } while (1);
        } else {
                std::cout << "User detals are invalid!!" << "\n";
                //;
            }

    } while (1);

    return 0;
}
