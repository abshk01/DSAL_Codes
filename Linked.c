#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node* next;

};

char choice;

int main(){

    struct node *head = NULL;
    struct node *temp = NULL;

    do{

        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            printf("Element inserted at head\n");
        } else {
            newnode->next = head;
            head = newnode;
            printf("Element inserted before head\n");
        }

        temp = head;
        printf("Linked List: ");
        if (temp == NULL) {
            printf("Linked List is empty");
        } else {
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
        }

        printf("NULL\n");

        printf("Do you want to continue (y/n) \n");
        scanf(" %c", &choice);

    } while(choice != 'n');


    temp = head;
    printf("Final linked Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    while (head != NULL) {
        struct node *current = head;
        head = head->next;
        free(current);
    }

    free(temp);
    return 0;
}




//struct for node
//declare pointer - newnode, head, temp
//create a node using malloc
//read data for that node
//handle link part of the node
//Insert at the biggening


printf("\n---- Main Menu ----\n");
printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);

switch (choice) {
    case 1: // INSERT MENU
        printf("\n-- Insert Menu --\n");
    printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
    printf("Enter choice: ");
    scanf("%d", &subChoice);
    printf("Enter value: ");
    scanf("%d", &val);

    switch (subChoice) {
        case 1: insertAtBeginning(val); break;
        case 2: insertAtEnd(val); break;
        case 3:
            printf("Enter position: ");
        scanf("%d", &pos);
        insertAtPosition(val, pos);
        break;
        default: printf("Invalid choice!\n");
    }
    break;

    case 2: // DELETE MENU
        printf("\n-- Delete Menu --\n");
    printf("1. Delete at Beginning\n2. Delete at End\n3. Delete at Position\n");
    printf("Enter choice: ");
    scanf("%d", &subChoice);

    switch (subChoice) {
        case 1: deleteAtBeginning(); break;
        case 2: deleteAtEnd(); break;
        case 3:
            printf("Enter position: ");
        scanf("%d", &pos);
        deleteAtPosition(pos);
        break;
        default: printf("Invalid choice!\n");
    }
    break;

    case 3:
        traverse();
    break;

    case 4:
        printf("Exiting program...\n");
    exit(0);

    default:
        printf("Invalid choice!\n");
}
    }

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // Global head pointer

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// INSERT OPERATIONS ------------------------
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int value, int pos) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// DELETE OPERATIONS ------------------------
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

// TRAVERSE ------------------------
void traverse() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// MAIN MENU ------------------------
int main() {
    int choice, subChoice, val, pos;

    while (1) {
        printf("\n---- Main Menu ----\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // INSERT MENU
                printf("\n-- Insert Menu --\n");
                printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);
                printf("Enter value: ");
                scanf("%d", &val);

                switch (subChoice) {
                    case 1: insertAtBeginning(val); break;
                    case 2: insertAtEnd(val); break;
                    case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        insertAtPosition(val, pos);
                        break;
                    default: printf("Invalid choice!\n");
                }
                break;

            case 2: // DELETE MENU
                printf("\n-- Delete Menu --\n");
                printf("1. Delete at Beginning\n2. Delete at End\n3. Delete at Position\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);

                switch (subChoice) {
                    case 1: deleteAtBeginning(); break;
                    case 2: deleteAtEnd(); break;
                    case 3:
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        deleteAtPosition(pos);
                        break;
                    default: printf("Invalid choice!\n");
                }
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
