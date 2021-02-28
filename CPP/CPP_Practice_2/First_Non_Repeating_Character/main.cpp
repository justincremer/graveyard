#include <iostream>
#include <string>

struct charAndIndex {
	std::string reference;
	char character;
	int index;
};

charAndIndex firstNonRepeatingChar(std::string input)
{
	charAndIndex result {.reference = input};
	int table[26] {0};
	for(int i = 0; i < (int) input.length(); i++) {
		table[input[i] - 97]++;
	}
	for(int i = 0; i < (int) input.length(); i++) {
		if(table[input[i] - 97] == 1) {
			result.character = input[i];
			result.index = i;
			break;
		}
	}
	return result;
}

void printResult(charAndIndex input)
{
	std::cout << "Input: " << input.reference << std::endl;
	for(int i = 0; i < input.index; i++) std::cout << " ";
	std::cout << "       ^" << std::endl;
	std::cout << "Character: " << input.character << std::endl;
	std::cout << "Index: " << input.index << std::endl;
}

int main()
{
	printResult(firstNonRepeatingChar("asdfqwerbasdqwertafkdshfbnczxbrqwpeouythgaisdjffad"));
	return 0;
}
