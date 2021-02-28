#ifndef _RESOURCE_H_
#define _RESOURCE_H_
#include <iostream>
#include <string>

using namespace std;

class Resource {
	private:
		string name;
		int amount = 0;
		int mod = 1;
	public:
		void setName(string input) {name = input;}
		string getName() {return name;}
		void incrementAmount() {amount += mod;}
		void incrementMod() {mod *= 2;}
		void printResource() {cout << name << ": " << amount << endl;}
};

#endif