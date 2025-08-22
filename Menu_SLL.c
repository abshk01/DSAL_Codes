#include <stdio.h>
#include <stdlib.h>

char repeat;

struct node {
    int data;
    struct node* next;
};

// Insert at beginning
void insertBeginning(struct node** head) {
    printf("Enter data: ");
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void insertEnd(struct node** head) {
    printf("Enter data: ");
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void deleteAtBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

//Insert a Position
void Insertpos(struct node** head) {
    int pos, data;
    printf("Enter Position you want to insert at -> ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &data);
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    struct node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAtEnd(struct node** head) {

    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {

        free(*head);
        *head = NULL;
        return;
    }
    struct node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void DeletePos(struct node** head) {
    int pos;
    printf("Enter Position you want to delete at -> ");
    scanf("%d", &pos);


    struct node* temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }
    struct node* toDel = temp->next;
    temp->next = temp->next->next;
    free(toDel);
}

void traverse(struct node* head) {
    struct node* temp = head;
    printf("Linked List: \n");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
}

int main() {
    struct node* head = NULL;

    do {
        int choice;
        int subChoice;

        printf("\n---- Operation on Singly Linked List----\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n-- Insert --\n");
                printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        insertBeginning(&head);
                        break;
                    case 2:
                        insertEnd(&head);
                        break;
                    case 3:
                        Insertpos(&head);
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 2:
                printf("\n-- Delete --\n");
                printf("1. Delete at Beginning\n2. Delete at End\n3. Delete at Position\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1: deleteAtBeginning(&head);
                        break;
                    case 2: deleteAtEnd(&head);
                        break;
                    case 3: DeletePos(&head);
                        break;
                    default:
                        printf("Invalid choice\n");
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("Empty List\n");
                    break;
                }
                traverse(head);
                break;
            case 4:
                printf("Exiting the Program\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        printf("\n Do you want to continue (y/n) \n");
        scanf(" %c", &repeat);
    } while (repeat != 'n');


    while (head != NULL) {
        struct node* current = head;
        printf(" \n Freed value %d\n",current->data);
        head = head->next;
        free(current);
    }
    return 0;
}
