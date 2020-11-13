#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
#include <windows.h>

typedef struct node {
	int data;
	struct node *next;
} node;

node *head = NULL;

void createNodeBeginning(int i) {
	if(head == NULL) {
		node *p = new node;
		p->data = i;
		p->next = NULL;
		head = p;
		std::cout << "list was empty" << std::endl;
	}
	else {
		node *temp = head;
		node *p = new node;
		p->data = i;
		p->next = temp;
		head = p;
		std::cout << "new node" << std::endl;
	}
}

void display() {
	node *tracer = head;

	while(tracer != NULL) {
		std::cout << tracer->data << " ";
		tracer = tracer->next;
	}
	std::cout << std::endl;
}

#endif // LIST_H