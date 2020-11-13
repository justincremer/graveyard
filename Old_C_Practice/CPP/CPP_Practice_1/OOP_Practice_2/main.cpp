#include <iostream>
#include <Account.h>
#include <stdlib.h>
#include <string>
#include <windows.h>

int main() {
	//INITIALIZE ACCOUNT
	Account myAccount;
	//string temp;
	//std::cout << "Enter your name: ";
	//std::cin >> temp;
	//myAccount.setName(temp);	
	std::cout << "Welcome, " << myAccount.getName() << std::endl;
	Sleep(2000);
	//PROGRAM LOOP
	for(int i = 0; i < 15; i++) {
		system("CLS");
		myAccount.printAccount();
		Sleep(500);
		for(int i = 0; i < 10; i++) {
			if((rand() % 10 + 1 ) > 6)
				myAccount.deposit(rand() % 100 + 101);
			else
				myAccount.withdraw(rand() % 100 + 51);
			Sleep(50);
		}
	}
	Sleep(500);
	cout << "\nTransactions complete";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "." << endl;
	Sleep(500);
	return 0;
}