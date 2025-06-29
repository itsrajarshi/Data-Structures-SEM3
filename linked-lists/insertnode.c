#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertatbeginning(struct node** head, int newdata)
{
  struct node* newnode = createnode(newdata);
  newnode->next = *head;
  *head = newnode;
}

void insertatend(struct node** head, int newdata)
{
  struct node* newnode = createnode(newdata);
  if(*head == NULL)
  {
    *head = newnode;
    return;
  }
  struct node* temp = *head;
  while(temp->next != NULL)
    {
      temp = temp->next;
    }
  temp->next = newnode;
}

void insertafternode(struct node* prevnode, int newdata);
newnode->next = prevnode->next;