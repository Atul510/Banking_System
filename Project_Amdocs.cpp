#include <bits/stdc++.h>
#include "AllFunctions.h"
using namespace std;

class Account{
    protected:
        string bank_name;
        string ifsc; // validation
        
    public:
        Account()
        {
            bank_name = "BANK OF INDIA";
            ifsc="SBIN0002108";
        }

};

class SavingAccount : public Account{
        
    string name;
    long acc_no;  
    string acc_type;  
    string pan;   
    double balance; 
public:
    SavingAccount():Account(){
        acc_no = generateAccountNumber();
        acc_type = "savings";
        balance = 0.0;
    }

    void getDetails(){
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Enter your Name: ";
        // cin.ignore();
        getline(cin,name);
        cout<<"Enter your PAN: ";
        while(true){
            cin >> pan;
            if (isValidPAN(pan)) {
                for (int i = 0; i < pan.length(); i++) {
                    pan[i] = toupper(pan[i]);
                }
                break;
            }
            else 
                cout << "Invalid PAN. Please enter a valid PAN: ";
        }
    }
    
    void deposit(double amt){
        if (amt > 0) {
            balance += amt;
            cout << "\nDeposited " << amt << ". New balance: " << balance << "\n\n";
        } else {
            cout << "Please enter a valid amount." << endl;
        }
    }     

    void withdraw(int amt) {
        if (amt > balance || (amt > 0 && balance - amt < 3000)) {
            cout << "Withdrawal not allowed. Enter within your limit." << "\n\n";
        } else {
            balance -= amt;
            cout << "Withdrawn amount: " << amt << ". New balance: " << balance << "\n\n";
        }
    }

    void displaydetails(){
        cout << "Bank Name: " << bank_name << endl;
        cout << "Account Type: " << acc_type << endl;
        cout << "Account Number: " << acc_no << endl;
        cout << "Account Holder Name: " << name << endl;
        cout << "PAN: " << pan << endl;
        cout << "IFSC: " << ifsc << endl;
        cout << "Balance: " << balance << "\n\n";
    }

    long getAccNo(){return acc_no;}

    double getBalance(){return balance;}

};

class CurrentAccount : public Account{

    string name;
    long acc_no;  
    string acc_type;  
    string pan;   
    double balance; 

public:
    CurrentAccount():Account(){
        acc_no = generateAccountNumber();
        acc_type = "current";
        balance = 0.0;
    }

    void getDetails(){
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Enter your Name: ";
        // cin.ignore();
        getline(cin, name);

        cout<<"Enter your PAN: ";
        while(true){
            cin >> pan;
            if (isValidPAN(pan)) {
                for (int i = 0; i < pan.length(); i++) {
                    pan[i] = toupper(pan[i]);
                }
                break;
            }
            else 
                cout << "Invalid PAN. Please enter a valid PAN: ";
        }
        cout<<endl;
    }

    void deposit(double amt){
        if (amt > 0) {
            balance += amt;
            cout << "\nDeposited " << amt << ". New balance: " << balance << "\n\n";
        } else {
            cout << "Please enter a valid amount." << endl;
        }
    }     

    void withdraw(int amt) {
        if (amt > balance || (amt > 0 && balance - amt < 10000)) {
            cout << "Withdrawal not allowed. Enter within your limit." << "\n\n";
        } else {
            balance -= amt;
            cout << "Withdrawn amount: " << amt << ". New balance: " << balance << "\n\n";
        }
    }

    void displaydetails(){
        cout << "Bank Name: " << bank_name << endl;
        cout << "Account Type: " << acc_type << endl;
        cout << "Account Number: " << acc_no << endl;
        cout << "Account Holder Name: " << name << endl;
        cout << "PAN: " << pan << endl;
        cout << "IFSC: " << ifsc << endl;
        cout << "Balance: " << balance << "\n\n";
    }

    long getAccNo(){return acc_no;}

    double getBalance(){return balance;}
};

int main(){
    unordered_map<long, SavingAccount> sAccMap;
    unordered_map<long, CurrentAccount> cAccMap;
    string name, pan;
    while(1){
        cout<<"1. Open Account\n2. Withdrawl\n3. Deposit\n4. Fund Transfer\n";
        cout<<"5. Balance Statement\n6. Display the Bank Database\n7. Exit\n\n";
        
        bool flag = false;
        cout<<"Enter your Choice: ";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:{ 
                cout<<"Select Account type, S for savings and C for current: ";
                char ch; cin>>ch;

                if(ch=='S' || ch=='s'){
                    SavingAccount sa;  // 5 details initialises
                    sa.getDetails();   // Rest 2 initialises here 
                    cout<<"Deposit atleast 3000 as per the bank policy: ";
                    int amt;    cin>>amt;
                    sa.deposit(amt);
                    sa.displaydetails();
                    sAccMap[sa.getAccNo()] = sa;
                
                }else if(ch=='C' || ch=='c'){
                    CurrentAccount ca;  // 5 details initialises
                    ca.getDetails();   // Rest 2 initialises here 
                    cout<<"Deposit atleast 10000 as per the bank policy: ";
                    int amt;    cin>>amt;
                    ca.deposit(amt);
                    ca.displaydetails();
                    cAccMap[ca.getAccNo()] = ca;
                }
                break;
            }
            case 2:{
                cout<<"Enter A/c Number: ";
                long ac_no; cin>>ac_no;

                cout<<"Enter the amount you want to withdraw: ";
                int money;  cin>>money;
                
                if(sAccMap.find(ac_no) != sAccMap.end())
                    sAccMap[ac_no].withdraw(money);
                else if(cAccMap.find(ac_no) != cAccMap.end())
                    cAccMap[ac_no].withdraw(money);
                else
                    cout<<"Invalid A/c No";
                break;
            }
            case 3:{
                cout<<"Enter A/c Number: ";
                long ac_no; cin>>ac_no;

                cout<<"Enter the amount you want to deposit: ";
                int money;  cin>>money;

                if(sAccMap.find(ac_no) != sAccMap.end())
                    sAccMap[ac_no].deposit(money);
                else if(cAccMap.find(ac_no) != cAccMap.end())
                    cAccMap[ac_no].deposit(money);
                else
                    cout<<"Invalid A/c No.\n\n";

                break;
            }
            case 4:{
                cout<<"Enter sender's A/c No: ";
                long fromAccountNo;    cin>>fromAccountNo;

                if(sAccMap.find(fromAccountNo) != sAccMap.end()){
                    SavingAccount sender_account = sAccMap[fromAccountNo];
                    cout<<"Enter receiver A/c No: ";
                    long toAccountNo;    cin>>toAccountNo;
                    
                    if(sAccMap.find(toAccountNo) != sAccMap.end()){

                        SavingAccount reciever_account = sAccMap[toAccountNo];
                        cout<<"Enter amount to transfer: ";
                        int amount;    cin>>amount;
                        
                        sender_account.withdraw(amount);    reciever_account.deposit(amount);
                        // Print sender's Balance and Receiver Balance
                    
                    } else if(cAccMap.find(toAccountNo) != cAccMap.end()){

                        CurrentAccount reciever_account = cAccMap[toAccountNo];
                        cout<<"Enter amount to transfer: ";
                        int amount;    cin>>amount;
                        
                        sender_account.withdraw(amount);    reciever_account.deposit(amount);

                    } else
                        cout<<"Invalid receiver's A/c No!!!\n\n";
                }
                else if(cAccMap.find(fromAccountNo) != cAccMap.end()){
                    CurrentAccount sender_account = cAccMap[fromAccountNo];
                    cout<<"Enter receiver A/c No: ";
                    long toAccountNo;    cin>>toAccountNo;

                    if(sAccMap.find(toAccountNo) != sAccMap.end()){

                        SavingAccount reciever_account = sAccMap[toAccountNo];
                        cout<<"Enter amount to transfer: ";
                        int amount;    cin>>amount;

                        sender_account.withdraw(amount);    reciever_account.deposit(amount);
                    
                    } else if(cAccMap.find(toAccountNo) != cAccMap.end()){

                        CurrentAccount reciever_account = cAccMap[toAccountNo];
                        cout<<"Enter amount to transfer: ";
                        int amount;    cin>>amount;

                        sender_account.withdraw(amount);    reciever_account.deposit(amount);

                    } else
                        cout<<"Invalid receiver's A/c No!!!\n\n";
                }
                else
                    cout<<"Invalid sender's A/c No!!!\n\n";
                break;
            }
            case 5:{
                cout<<"Enter A/c no: ";
                int ac_no; cin>>ac_no;

                if(sAccMap.find(ac_no) != sAccMap.end())
                    cout << "Balance: " << sAccMap[ac_no].getBalance()<<endl<<endl;
                else if(cAccMap.find(ac_no) != cAccMap.end())
                    cout<< "Balance: " << cAccMap[ac_no].getBalance()<<endl<<endl;
                else
                    cout<<"Invalid A/c No\n\n";
                break;
            }    
            case 6:{
                cout<<"All Savings Accounts: \n\n";
                for (const auto& pair : sAccMap) {
                    long accountNumber = pair.first;
                    SavingAccount account = pair.second;

                    // Display the account details
                    account.displaydetails();
                    cout << endl;
                }
                cout<<"\nAll Current Accounts: \n\n";
                for (const auto& pair : cAccMap) {
                    long accountNumber = pair.first;
                    CurrentAccount account = pair.second;

                    // Display the account details
                    account.displaydetails();
                    cout << endl;
                }
                break;
            }
            case 7:{
                cout << "Exiting the program....\nThank you using our Banking System:)\n" << endl;
                flag = true;
                break;
            }
            default:
                cout<<"Enter valid choice!!!"; break;
        }
        if(flag)break;
    }
    return 0;
}

