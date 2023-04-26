#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
private:
    string name;
    string mobile;
    string pin;
    int account_number;
    float balance;
public:
    Account(string n, string m, string p, int acc_no) {
        name = n;
        mobile = m;
        pin = p;
        account_number = acc_no;
        balance = 0.0;
    }
    string getName() {
        return name;
    }
    string getMobile() {
        return mobile;
    }
    string getPin() {
        return pin;
    }
    int getAccountNumber() {
        return account_number;
    }
    float getBalance() {
        return balance;
    }
    void deposit(float amount) {
        balance += amount;
        cout << "Amount deposited successfully. New balance: " << balance << endl;
    }
    void withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Amount withdrawn successfully. New balance: " << balance << endl;
        }
        else {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        }
    }
    void updateAccount(string n, string m, string p) {
        name = n;
        mobile = m;
        pin = p;
        cout << "Account details updated successfully." << endl;
    }
};

vector<Account> accounts;

void openAccount() {
    string name, mobile, pin;
    int account_number = accounts.size() + 1;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your mobile number: ";
    cin >> mobile;
    cout << "Enter your 4-digit PIN: ";
    cin >> pin;
    Account acc(name, mobile, pin, account_number);
    accounts.push_back(acc);
    cout << "Account created successfully. Your account number is: " << account_number << endl;
}

void showAccountDetails() {
    int acc_no;
    string pin;
    cout << "Enter your account number: ";
    cin >> acc_no;
    cout << "Enter your PIN: ";
    cin >> pin;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == acc_no && accounts[i].getPin() == pin) {
            cout << "Name: " << accounts[i].getName() << endl;
            cout << "Mobile: " << accounts[i].getMobile() << endl;
            cout << "Account Number: " << accounts[i].getAccountNumber() << endl;
            cout << "Balance: " << accounts[i].getBalance() << endl;
            return;
        }
    }
    cout << "Invalid account number or PIN." << endl;
}

void deposit() {
    int acc_no;
    string pin;
    float amount;
    cout << "Enter your account number: ";
    cin >> acc_no;
    cout << "Enter your PIN: ";
    cin >> pin;
    cout << "Enter the amount to be deposited: ";
    cin >> amount;
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getAccountNumber() == acc_no && accounts[i].getPin() == pin) {
            accounts[i].deposit(amount);
            return;
        }
    }
    cout << "Invalid account number or PIN." << endl;
}

int main() {
    int choice;
    cout << "Welcome to the bank. Please select an option:" << endl;
    cout << "1. Open an account" << endl;
    cout << "2. Show account details" << endl;
    cout << "3. Deposit money" << endl;
    cout << "4. withdraw money" << endl;
    cout << "5. Update account details" << endl;
    cout << "6. Exit" << endl;

    do {
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                openAccount();
                break;
            case 2:
                showAccountDetails();
                break;
            case 3:
                deposit();
                break;
            case 4:
               // withdraw money();
                break;
            case 5:
      //          updateAccount();
                break;
            case 6:
                cout << "Thank you for using our services. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
void withdrawAmount() {
    int accountNo, pinNo;
    float amount;
    bool isFound = false;

    cout << "\n=== Withdraw Amount ===\n";
    cout << "Enter your account number: ";
    cin >> accountNo;
    cout << "Enter your PIN number: ";
    cin >> pinNo;

   // for (int i = 0; i < numAccounts; i++) {
       // if (accounts[i].getAccountNo() == accountNo && accounts[i].getPinNo() == pinNo) {
            isFound = true;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
          //  if (amount <= accounts[i].getBalance()) {
               // accounts[i].withdraw(amount);
                cout << "\nWithdrawal successful!\n";
                cout << "Withdrawn amount: " << amount << "\n";
           //     cout << "Current balance: " << accounts[i].getBalance() << "\n";
          //  } else {
                cout << "\nWithdrawal failed! Insufficient balance.\n";
            }
  //          break;
   //     }
  //  }

   // if (!isFound) {
     //   cout << "\nAccount not found or invalid PIN number.\n";
  //  }
//}
