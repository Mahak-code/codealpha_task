#include<iostream>
#include<string>
#include<vector>
using namespace std;
class transaction{
    //transaction class
    public:
    string type;//deposit or withdraw,transfer
    double amount;
    string details;  
    
    transaction(string t,double a,string d){
    type =t;
    amount=a;
    details=d;
}
void showTransaction() const {
    cout<<type<<" "<<amount<<" "<<details<<endl;
}
};


//Account class
class Account{
    public:
    int accountNumber;
    double balance;
    vector <transaction>history; //vector of transaction objects
    Account(int accNum,double bal){
        accountNumber=accNum;
        balance=bal;
    }
    void deposit(double amount){
        balance+=amount;
        history.push_back(transaction("Deposit",amount,"Self Deposit"));
        cout<<"Amount successfully Deposited: "<<amount<<endl;
        //history.push_back(...) → Adds a new transaction object to the history list (like recording the deposit in a passbook)

} 
void withdraw(double amount){
    if (amount > balance) {
    cout << "Transaction failed: Insufficient balance!" << endl;
} else {
    // proceed with withdrawal
    balance-= amount;
    history.push_back(transaction("Withdraw", amount, "Self Withdrawal"));
    cout << "Amount successfully withdrawn: " << amount << endl;
   
}
}
void transfer(Account &toAccount, double amount) {
    if (amount > balance) {
        cout << "Transaction failed: Insufficient balance for transfer!" << endl;
    } else {
        // Deduct from this account
        balance -= amount;
        history.push_back(transaction("Transfer", amount, "Transferred to Acc: " + to_string(toAccount.accountNumber)));

        // Add to receiver's account
        toAccount.balance += amount;
        toAccount.history.push_back(transaction("Transfer", amount, "Received from Acc: " + to_string(accountNumber)));

        cout << "Amount successfully transferred: " << amount 
             << " to Account " << toAccount.accountNumber << endl;
    }
}

void showaccountinfo() const{
    cout<<"----****your Account Information****---- "<<endl;
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"Balance: "<<balance<<endl;
    cout<<"Transaction History: "<<endl;
    for (const auto &trans : history) {
        trans.showTransaction();
      
    }
}
    };

    //customer class
class customer{
    public:
    string name;
    Account account; // Declare Account member variable
    customer(string n,int accNum) : name(n), account(accNum, 0.0) {
        // name is initialized above, account is initialized with accNum and zero balance
    }
    void showCustomerInfo(){
        cout<<"Customer Name: "<<name<<endl;
        account.showaccountinfo();
    }
};

//main function
int main(){
    customer c1("Mahak",12345);
    customer c2("saxena",67890);
 
    c1.account.deposit(95000);
    c1.account.withdraw(90000);
    c1.showCustomerInfo();
    
    c2.account.deposit(500000);
    c2.account.transfer(c1.account,20000);
    c2.account.withdraw(1000);
    c2.showCustomerInfo();
    return 0;
}
