#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>

typedef struct node {
    char data;
    struct node *nextPtr;
} node_t;
typedef node_t *listNodePtr;


void insertBeginning(listNodePtr *head, char val) {
    listNodePtr node = malloc(sizeof(node_t));
    node->data = val;
    node->nextPtr = *head;
    *head = node;
}


void insertEnd(listNodePtr *head, char val) {
    listNodePtr current = *head;
    if(current != NULL) {
        while (current->nextPtr != NULL) {
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = val;
        current->nextPtr->nextPtr = NULL;
    }
    else {
        current = malloc(sizeof(node_t));
        current->nextPtr->data = val;
        current->nextPtr->nextPtr = NULL;
        *head = current;
    }
}


void insert(listNodePtr *head, char val) {
    listNodePtr newPtr;
    listNodePtr previousPtr;
    listNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));

    if(newPtr != NULL) {
        newPtr->data = val;
        newPtr->nextPtr = NULL;

        previousPtr = NULL;
        currentPtr = *head;

        while(currentPtr != NULL && val > currentPtr->data) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if (previousPtr == NULL) {
            newPtr->nextPtr = *head;
            *head = newPtr;
        }
        else {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else printf("No memory avaliable");
}


void delBeginning(listNodePtr *head) {
    listNodePtr tempPtr = NULL;

    if (head == NULL) {
        return;
    }
    else {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
    }
}


char del(listNodePtr *head, char val) {
    listNodePtr previousPtr;
    listNodePtr currentPtr;
    listNodePtr tempPtr;

    if(val == (*head)->data) {
        tempPtr = *head;
        *head = (*head)->nextPtr;
        free(tempPtr);
        return val;
    }
    else {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;

        while(currentPtr != NULL && currentPtr->data != val) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        if(currentPtr != NULL) {
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return val;
        }
    }
    return '\0';
}


void printList(listNodePtr currentPtr) {
    if (currentPtr == NULL)
        printf("List is empty\n\n");
    else {
        while(currentPtr != NULL) {
            printf("%c -> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}


BOOL isEmpty(listNodePtr head) {
    return (head == NULL);
}


void displayAndLogic() {
    static listNodePtr *head = NULL;
    char item;
    int choice;

    printf("What would you like to do?\n\n"
               "   1 to insert an element into the list alphabetically\n"
               "   2 to insert an element at the end of the list\n"
               "   3 to insert an element at the beginning of the list\n"
               "   4 to delete an element from the list\n"
               "   5 to delete an element from the beginning of the list\n"
               "   6 to end the program\n\n"
               "user$"
               );
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\n\nEnter a character\nuser$");
            scanf("%c\n", &item);
            insert(head, item);
            printList(*head);
            printf("worked");
            break;
        case 2:
            printf("\n\nEnter a character\nuser$");
            scanf("%c\n", &item);
            insertEnd(head, item);
            printList(*head);
            break;
        case 3:
            printf("\n\nEnter a character\nuser$");
            scanf("%c\n", &item);
            insertBeginning(head, item);
            printList(*head);
            break;
        case 4:
            if(!isEmpty(head)) {
                printf("\n\nEnter a character\nuser$");
                scanf("%c\n", &item);
                if(del(&head, item)) {
                    printf("%c deleted\n", item);
                    printList(head);
                }
                else printf("%c not found\n", item);
            }
            else printf("List is empty\n");
            break;
        case 5:
            if(!isEmpty(head)) {
                delBeginning(&head);
                printf("\n%c deleted\n", item);
                printList(head);
            }
            else printf("List is empty\n");
            break;
        case 6:
            printf("\nEnding the program");
            Sleep(1500);
            printf("\n\nGoodbye Friend");
            Sleep(3000);
            exit(0);
            break;
        default:
            printf("You need to enter an integer from 1 - 6\n\n");
            break;
        }
}


int main() {
    printf("Hello friend\n\n");

    while(1) {
        displayAndLogic();
        Sleep(5000);
    }
    return 0;
}
