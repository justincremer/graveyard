#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

class Array
{
private:
	int *p;
	int length;
public:
	Array(int *p_val = NULL, int len_val = 0);

	int* getArray();
	int getLength();
	int getMax();
	int getAverage();

	void display();

	void setIndex(int index, int x);
	void insert(int index, int x);
	void remove(int index);

	void pop();
	void push(int x);
	void shift();
	void unshift(int x);
	void swap(int x, int y);
	void reverse();

	int linearSearch(int x);
	int binarySearch(int x);

	void merge(Array x, Array y);

	bool isSorted();
	void bubbleSort();
	void mergeSort(int* arr, int low, int high)
};

#endif // ARRAY_H
