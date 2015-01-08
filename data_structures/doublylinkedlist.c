#include<stdio.h>
#include<stdlib.h>

struct node
{
  int value;
  struct node* next;
  struct node* previous;
};

typedef struct node node;

node* GetNewNode(int value)
{
  node* newNode = (node*)malloc(sizeof(node));
  newNode->value = value;
  newNode->next = NULL;
  newNode->previous = NULL;
  return newNode;

}

void InsertAtHead(int value, node** headptr)
{
  struct node* newNode = GetNewNode(value);
  if(*headptr == NULL)
  {
    *headptr = newNode;
    return;
  }
  (*headptr)->previous = newNode;
  newNode->next = *headptr;
  *headptr = newNode;
}

void InsertAtTail(int value, node** headptr)
{
  struct node* newNode = GetNewNode(value);
  struct node* tempHead = *headptr;
  if(*headptr == NULL)
  {
    *headptr = newNode;
    return;
  }

  while(tempHead->next != NULL)
  {
    tempHead = tempHead->next;
  }

  newNode->previous = tempHead;
  tempHead->next = newNode;
}

void Print(node* head)
{
  while(head != NULL)
  {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}

void PrintReverse(node* head)
{
  while(head->next != NULL)
  {
    head = head->next;
  }
  while(head != NULL)
  {
    printf("%d ", head->value);
    head = head->previous;
  }
  printf("\n");
}

int main(void)
{
  node* head;
  InsertAtHead(5, &head);
  InsertAtHead(6, &head);
  InsertAtHead(7, &head);
  InsertAtHead(8, &head);
  InsertAtTail(9, &head);
  Print(head);
  PrintReverse(head);
}
