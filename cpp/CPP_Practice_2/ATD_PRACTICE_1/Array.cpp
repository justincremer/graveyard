#include "Array.h"

Array::Array(int *p_val, int len_val):
	p{ p_val }, length{ len_val } {}

int* Array::getArray()
{
	return p;
}

int Array::getLength()
{
	return length;
}

int Array::getMax()
{
	if(length <= 0) return -1;
	int result = 0;
	for(int i = 0; i < length; i++) {
		if(p[i] > result) result = p[i];
	}
	return result;
}

int Array::getAverage()
{
	if(length <= 0) return -1;
	float result = 0;
	for(int i = 0; i < length; i++) {
		result += (float) p[i];
	}
	return (result / length);
}

void Array::display()
{
	int *temp = p;

	for(int i = 0; i < length; i++) {
		std::cout << *p << " ";
		p++;
	}

	std::cout << "\nLength: " << length << std::endl; ;
	p = temp;
	temp = NULL;
}

void Array::setIndex(int index, int x)
{
	if(index >= 0 && index < length) {
		p[index] = x;
	}

	else
		std::cout << "Index not in array" << std::endl;
}

void Array::insert(int index, int x)
{
	if(index >= length)
		push(x);

	else if(index >= 0) {
		int *temp = new int[length + 1];
		int *start = temp;
		int count = 0;
		for(int i = 0; i < index; i++) {
			*temp = p[i];
			temp++;
			count++;
		}

		*temp = x;
		temp++;

		for(int i = count; i < length + 1; i++) {
			*temp = p[i];
			temp++;
		}

		//delete p;
		p = start;
		length++;
		temp = NULL;
		start = NULL;
	}

	else
		std::cout << "Index cannot be negative" << std::endl;
}

void Array::remove(int index)
{
	if(index < 0 || index >= length) {
		std::cout << "Index not in the array" << std::endl;
	} else {
		int *temp = new int[length - 1];
		int *start = temp;
		for(int i = 0; i < length; i++) {
			if(i == index) {}
			else {
				*temp = p[i];
				temp++;
			}
		}
		p = start;
		length--;
		temp = NULL;
		start = NULL;
	}
}

void Array::pop()
{
	int* temp = new int[length - 1];
	for(int i = 0; i < length - 1; i ++) {
		temp[i] = p[i];
	}
	delete p;
	p = temp;
	length--;
	temp = NULL;
}

void Array::push(int x)
{
	if(length <= 0) {
		int* temp = new int[1];
		*temp = x;
		delete p;
		p = temp;
		length++;
		temp = NULL;
	} else {
		int *temp = new int[length + 1];

		for(int i = 0; i < length; i ++) {
			temp[i] = p[i];
		}

		temp[length] = x;
		delete p;
		p = temp;
		length++;
		temp = NULL;
	}
}

void Array::shift()
{
	int *temp = new int[length - 1];
	for(int i = 0; i < length - 1; i++) {
		temp[i] = p[i + 1];
	}
	delete p;
	p = temp;
	length--;
	temp = NULL;
}

void Array::unshift(int x)
{
	int *temp = new int[length + 1];
	*temp = x;

	for(int i = 0; i < length; i ++) {
		temp[i + 1] = p[i];
	}
	delete p;
	p = temp;
	length++;
	temp = NULL;
}

void Array::swap(int x, int y)
{
	int temp = p[x];
	p[x] = p[y];
	p[y] = temp;
}

void Array::reverse()
{
	if(length <= 0) return;
	int* temp = new int[length];

	int i = 0;
	for(int j = length - 1; j >= 0; j--) {
		temp[i] = p[j];
		i++;
	}
	delete p;
	p = temp;
	temp = NULL;
}

int Array::linearSearch(int key)
{
	for(int i = 0; i < length; i++) {
		if(p[i] == key) {
			std::cout << "Key "<< key <<" found at index: " << i << std::endl;
			return i;
		}
	}
	std::cout << "Key not found" << std::endl;
	return -1;
}

int Array::binarySearch(int key)
{
	int h = length - 1;
	int m = h / 2;
	int l = 0;

	while(l <= h) {
		if(key == p[m]) {
			std::cout << "Key " << key << " found at index " << m << std::endl;
			return m;
		} else if(key > p[m]) {
			if(key == p[h]) {
				std::cout << "Key " << key << " found at index " << h << std::endl;
				return h;
			} else {
				l = m;
				m = (l + h) / 2;
			}
		} else if(key < p[m]) {
			if(key == p[l]) {
				std::cout << "Key " << key << " found at index " << l << std::endl;
				return l;
			} else {
				h = m;
				m = (l + h) / 2;
			}
		}
	}
	std::cout << "Key not found" << std::endl;
	return 1;
}

void Array::merge(Array x, Array y)
{
	int i = 0;
	int j = 0;
	int temp_length = x.getLength() + y. getLength();
	int* temp = new int[temp_length];

	for(int k = 0; k < temp_length; k++) {
		if(x.getArray()[i] <= y.getArray()[j]) {
			if(i < x.getLength()) {
				temp[k] = x.getArray()[i];
				i++;
			} else {
				temp[k] = y.getArray()[j];
				j++;
			}
		} else {

			if(j < y.getLength()) {
				temp[k] = y.getArray()[j];
				j++;
			} else {
				temp[k] = x.getArray()[i];
				i++;
			}
		}
	}

	delete p;
	p = temp;
	length = temp_length;
}

bool Array::isSorted()
{
	if(length == 0) return true;

	for(int i = 0; i < length - 1; i++) {
		if(p[i] > p[i + 1]) return false;
	}

	return true;
}

void Array::bubbleSort()
{
	if(isSorted()) return;

	for(int i = 0; i < length - 1; i++) {
		if(p[i] > p[i + 1]) {
			int temp = p[i + 1];
			p[i + 1] = p[i];
			p[i] = temp;
		}
	}

	bubbleSort();
}

void Array::merge(int* arr, int low, int mid, int high)
{

}

void Array::mergeSort(int* arr, int low, int high)
{
	int* temp = p;

	if(low < high) {
		int mid = (low + high) / 2;
		mergeSort(temp, low, mid);
		mergeSort(temp, mid+1, high);

		merge();
	}

	delete p;
	p = temp;
	temp = NULL;
}

void Array::merge(int low, int mid, int high);
{
	int i = 0;
	int j = 0;
	int temp_length = x.getLength() + y. getLength();
	int* temp = new int[temp_length];

	for(int k = 0; k < temp_length; k++) {
		if(x.getArray()[i] <= y.getArray()[j]) {
			if(i < x.getLength()) {
				temp[k] = x.getArray()[i];
				i++;
			} else {
				temp[k] = y.getArray()[j];
				j++;
			}
		} else {

			if(j < y.getLength()) {
				temp[k] = y.getArray()[j];
				j++;
			} else {
				temp[k] = x.getArray()[i];
				i++;
			}
		}
	}

	delete p;
	p = temp;
	length = temp_length;
}
