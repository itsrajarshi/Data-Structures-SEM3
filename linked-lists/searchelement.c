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
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

int search(struct node* head, int target)
{
  struct node* current = head;
  while (current != NULL)
    {
      if (current->data == target)
        return 1;
      current = current -> next;
    }
  return 0;
}

int main()
{
  struct node* head = createnode(10);
  head->next = createnode(20);
  head->next->next = createnode(30);
  head->next->next->next = createnode(40);

  int target = 30;

  if(search(head, target))
    printf("Element %d found in the linked list.\n", target);
  else
    printf("Element %d not found in the linked list.\n", target);
  return 0;
}