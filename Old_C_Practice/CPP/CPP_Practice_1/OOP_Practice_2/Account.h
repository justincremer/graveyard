#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
	string name = "";
	double balance = 0;	
public:
	void setName(string i) {name = i;}
	
	string getName() {return name;}
	
	void printAccount() {cout << "Account name: " << name << "\n" << "Balance: $" << balance << "\n\n" << endl;}
	
	void deposit(double i) {
		if (i > 0) {
			balance += i;
			cout << "$" << i << " deposit requested" << endl;
		}
	}
	
	void withdraw(double i) {
		if (i > 0 && balance - i >= 0) {
			balance -= i;
			cout << "$" << i << " withdrawl requested" << endl;
		}
		else cout << "Insufficient funds" << endl;
	} 
	
	Account() {
		name = "Justin";
		balance = 100;
	}
	
	~Account() {
		cout << "\nAccount deleted\n" << endl;
	}
};

#endif // _ACCOUNT_H_

