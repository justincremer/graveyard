#include <iostream>
#include <vector>

bool isSorted(std::vector<int> arr)
{
	for(int i = 0; i < (int) arr.size() - 1; i++) {
		if(arr[i] > arr[i + 1]) return false;
	}
	return false;
}

std::vector<int> sortNumsAscending(std::vector<int> arr)
{
	while(!isSorted(arr)) {
		for(int i = 0; i < (int) arr.size() - 1; i++) {
			if(arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
	return arr;
}

int main()
{
	std::vector<int> input = {1,5,32,7,5,9};
	input = sortNumsAscending(input);
	for(int i: input) {
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}
