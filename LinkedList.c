#include <stdio.h>
#include <stdlib.h>

struct node{

  int data;
  struct node* next;

};

char choice;

int main(){


  int menu_choice;
  int menu_subchoice;

printf("Enter choice:\n"
       "1 - Insert\n"
       "2 - Delete\n"
       "3 - Display\n"
       "4 - Exit\n");

switch (menu_choice) {


}












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
    while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
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