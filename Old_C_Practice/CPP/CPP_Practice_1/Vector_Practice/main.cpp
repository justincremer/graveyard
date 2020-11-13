#include <iostream>
#include <vector>
//
using namespace std;
//
vector <int> test_vector {1,2,3,4,5,6,7,8,9,10};


int main() {
	for(auto i : test_vector)
		cout << i << " -> ";
	cout << "NULL" << endl;
	return 0;
}
