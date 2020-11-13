#include <iostream>
#include <hanoi.h>

void f1(int n);
void f2(int n);
void f3(int n);
int sum(int n);
float fact(float n);
float pow(float n, float i);
float taylorSeries(float n, float i);

void f1(int n) {
	if(n > 0) {
		std::cout << n << " ";
		f2(n - 1);
	}
}

void f2(int n) {
	if(n > 0) {
		f1(n - 1);
		std::cout << n << " ";
	}
}

void f3(int n) {
	for(; n > 0; n--) {
		f1(n);
		std::cout << std::endl;
	}
}

int sum(int n) {
	if (n == 0) return n;
	else return (sum(n-1) + n);
}

float fact(float n) {
	if (n == 1) return 1;
	else return (fact(n-1) * n);
}

float pow(float n, float i) {
	if (i == 1) return n;
	else return (pow(n, i - 1) * n);
}

float taylorSeries(float n, float i) {
	if (i == 0) return 1;
	else return (taylorSeries(n, i - 1) + (pow(n, i) / fact(i)));
}

int main() {
	//f3(75);
	//std::cout << "recursive sum of 10: " << sum(10) << std::endl;
	//std::cout << "factorial of 5: " << fact(5) << std::endl;
	//std::cout << "2 ^ 5: " << pow(2, 5) << std::endl;
	//std::cout << "Taylor series for 2 and 3: " << taylorSeries(2, 3) << std::endl;
	hanoi(8, 'A', 'B', 'C');
	return 0;
}
