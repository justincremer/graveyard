#include <iostream>
#include <cstdlib> //malloc
#include <string>
#include <vector>

using namespace std;

typedef struct node {
	int i: 8; //max 128
	struct node *next;
} node;

void addNodeBeginning(node *head, int val);
void printList(node *head);


int main() {
	node *head = NULL;
	addNodeBeginning(head, 1);
	cout << head->i << endl;
	return 0;
}


void addNodeBeginning(node *head, int val) {
	node* temp = (node*)malloc(sizeof(node));
	temp->i = val;
	temp->next = head;
	head = temp;
}

void printList(node *head) {
	node** tracer = &head;
	while(*tracer != NULL) {
		cout << " -> " << (*tracer)->i;
		tracer = &(*tracer)->next;
	}
	cout << endl; 
}
