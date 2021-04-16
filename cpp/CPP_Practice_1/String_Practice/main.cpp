#include <iostream>
#include <cctype>
#include <string>

using namespace std;

string test = "Hello";

int main() {
	test +=  " World";
	
	for(char c: test) 
		cout << (char)toupper(c);
	cout << endl;
	
	return 0;
}


