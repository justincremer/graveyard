#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char value;
    struct node *next;
} node;

//node *head = NULL;

node box2 = {'O', NULL};
node box1 = {'Y', &box2};
node *head = &box1;
node **start = &head;

int isEmpty(node *head) {
    return (head == NULL) ? 1 : 0;
}

void printList(node **start) {
    start = &head;
    if(isEmpty(*start))
        printf("The list is empty\n");
    else {
        while(*start) {
            printf("-> %c ", (*start)->value);
            start = &(*start)->next;
        }
        printf("-> NULL");
    }
}

int main()
{
    printList(start);


    return 0;
}
