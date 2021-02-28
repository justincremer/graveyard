#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


int main() {
	fstream f {"test.txt", ios::in | ios::out};
	string line {};
	
	if(!f) {
		cout << "Unable to open file" << endl;
		Sleep(2000);
		return 1;
	}
	while(getline(f, line)) {
		cout << line << endl;
	}
	f.close();		
	return 0;
}