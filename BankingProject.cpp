#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <Windows.h>
using namespace std;

struct BankAccount{
    int accountNumber;
    string accountHolderName;
    double balance;
};

//Maximum number of accounts
const int MAX_ACCOUNTS = 100;
//Array to store accounts
BankAccount accounts[MAX_ACCOUNTS];
//Keep track of the number of accounts
int numberOfAccounts = 0;
//Create a new account
void createAccount(){
    cout<<"Preparing windows.."<<flush;
    this_thread::sleep_for(chrono::seconds(2));
    system("CLS");
    if(numberOfAccounts >=MAX_ACCOUNTS){
        cout<<"Maximum number of accounts reached!"<<endl;
        return;
    }

    BankAccount newAccount;
    cout<<"Enter account holder name: ";

    //We have used the getline function to input strings with blank spaces
    getline(cin>>ws, newAccount.accountHolderName);
    cout<<"Enter account number: ";

    cin>>newAccount.accountNumber;


    cout<<"Enter initial balance: ";
    cin>>newAccount.balance;

    accounts[numberOfAccounts] = newAccount;
    numberOfAccounts++;
            system("COLOR 0e");
            system("cls");

            char bar1 = 177, bar2=219;
            cout<<"\n\n\n\t\t\t\tSaving Account...";
            cout<<"\n\n\n\t\t\t\t";
            for(int i=0; i<25; i++){
                cout<<(char)bar1;
            }
            cout<<"\r";
            cout<<"\t\t\t\t";
            for(int i=0; i<25;i++){
                cout<<(char)bar2;
                Sleep(150);
            }
        cout<<"\n\t\t\t\tAccount created successfully!"<<flush;
        this_thread::sleep_for(chrono::seconds(3));
        system("CLS");

}

//Show details of account
void showAccountDetails(){
    system("cls");
    int accountNumber;
    cout<<"Enter account number: ";
    cin>>accountNumber;

    for(int i=0; i<numberOfAccounts; i++){
        if(accounts[i].accountNumber == accountNumber){
            cout<<"Account Number: "<<accounts[i].accountNumber<<endl;
            cout<<"Account Holder Name: "<<accounts[i].accountHolderName<<endl;
            cout<<"Balance: "<<accounts[i].balance<<" birr"<<endl;
            return;
        }
    }

    cout<<"Account not found!"<<endl;
}

//Deposit Money
void depositMoney() {
    int accountNumber;
    double amount;
    cout<<"Enter account number: ";
    cin>>accountNumber;

    for(int i=0; i<numberOfAccounts; i++){
        if(accounts[i].accountNumber == accountNumber){
            cout<<"Enter amount to deposit: ";
            cin>>amount;

            accounts[i].balance += amount;
            cout<<"Deposit successful! Updated balance: "<<accounts[i].balance<<" birr"<<endl;
            return;
        }
    }
    cout<<"Account not found!"<<endl;
}

//Withdraw money
void withdrawMoney(){
    int accountNumber;
    double amount;
    cout<<"Enter account number: ";
    cin>>accountNumber;

    for(int i=0; i<numberOfAccounts; i++){
        if(accounts[i].accountNumber == accountNumber){
            cout<<"Enter amount to withdraw: ";
            cin>>amount;

            if(accounts[i].balance>=amount){
                accounts[i].balance -= amount;
                cout<<"Withdraw successful! Updated balance: "<<accounts[i].balance<<" birr"<<endl;

            } else{
                cout<<"Insufficient balance!"<<endl;
            }
            return;
        }
    }
    cout<<"Account not found!"<<endl;
}

//Delete an account
void deleteAccount(){
    int accountNumber;
    cout<<"Enter account number: ";
    cin>>accountNumber;

    for(int i=0; i<numberOfAccounts; i++){
        if(accounts[i].accountNumber==accountNumber){
            for(int j=i; j<numberOfAccounts -1; j++){
                accounts[j] = accounts[j+1];
            }
            numberOfAccounts--;
            cout<<"Account deleted successfully!"<<endl;
            return;
        }
    }
    cout<<"Account not found!"<<endl;
}

int main(){
    int choice;
    system("COLOR 0e");
    do {
        cout<<endl;
        cout<<"====Banking System Menu===="<<endl;
        cout<<"1.Create Account"<<endl;
        cout<<"2.Show Account Details"<<endl;
        cout<<"3.Deposit Money"<<endl;
        cout<<"4.Withdraw Money"<<endl;
        cout<<"5.Delete Account"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
        case 1:
            createAccount();
            break;
        case 2:
            showAccountDetails();
            break;
        case 3:
            depositMoney();
            break;
        case 4:
            withdrawMoney();
            break;
        case 5:
            deleteAccount();
            break;
        case 6:
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Invalid choice!"<<endl;
            break;
        }
    }
    while(choice!=6);

    return 0;


}
