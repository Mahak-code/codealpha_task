#include<iostream>
#include<string>//for string handling
#include<fstream>//file handling
using namespace std;

void userRegister(string username, string password) {
    ofstream file("users.txt", ios::app); // Open file in append mode
    file <<username<<" "<<password<<endl; // Write username and password ( credentials )to file 
    file.close(); // Close the file
    cout << "Registration successful!" << endl;
    
}


void userLogin(string username, string password) {
    ifstream file("users.txt"); // Open file in read mode
    string fileUsername, filePassword;
    bool found = false;
    while (file >> fileUsername >> filePassword) { // Read username and password from file
        if (fileUsername == username && filePassword == password) {
            found = true;
            break;
        }
    }
    file.close();
    if (found) {
        cout << "Login successful!" << endl;

    }
    else {
        cout << "Invalid username or password!" << endl;
    }
}



int main(){
    int choice;
  string username,password;
   while(true){
    cout<<"=====**Menu**====="<<endl;
    cout<<"1. Register"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    cin.ignore(); // To ignore the newline character after integer input
    switch (choice)
    {
    case 1:
    cout<<"Enter username: ";
    getline(cin,username);
    cout<<"Enter password: ";
    getline(cin,password);
    userRegister(username,password);

    break;
    case 2: 
    cout<<"Enter username:\n ";
    getline(cin,username);
    cout<<"Enter password:\n ";
    getline(cin,password);
    userLogin(username,password);
    break;
    case 3:
    cout<<"Exiting..."<<endl;
    return 0;

    default:
        cout<<"Invalid choice"<<endl;

    }

    }
    
}