#include<stdio.h>
#include<stdlib.h>

struct node;
void Insert(int x, struct node** headptr);
void InsertAt(int data, int position, struct node** headptr);
void Print(struct node* head);
void Remove(int position, struct node** head);
void Reverse(struct node** headptr);
void RecursivePrint(struct node* head);
void ReversedRecursivePrint(struct node* head);
void RecursiveReverse(struct node* head, struct node** headptr);

int main(void) {
  struct node* head = NULL;
  int n, i, x;

  /*printf("How many numbers?\n");*/
  /*scanf("%d", &n);*/

  /*for (i = 0; i < n; i++)*/
  /*{*/
    /*printf("Enter the number \n");*/
    /*scanf("%d", &x);*/
    /*Insert(x, &head);*/
    /*Print(head);*/
  /*}*/
  head = NULL;
  InsertAt(2,0,&head);
  InsertAt(3,1,&head);
  InsertAt(4,0,&head);
  InsertAt(5,1,&head);
  /*Print(head);*/
  /*scanf("%d", &i);*/
  /*Remove(i, &head);*/
  /*Reverse(&head);*/
  /*Print(head);*/
  RecursivePrint(head);
  RecursiveReverse(head, &head);
  Print(head);
  /*ReversedRecursivePrint(head);*/

  return 0;
};

struct node
{
  int data;
  struct node* next;
};

void RecursivePrint(struct node* head)
{
  if (head->next == NULL)
  {
    printf("%d\n", head->data);
    return;
  }
  printf("%d, ", head->data);
  RecursivePrint(head->next);
}

void ReversedRecursivePrint(struct node* head)
{
  if (head == NULL)
  {
    return;
  }
  ReversedRecursivePrint(head->next);
  printf("%d, ", head->data);
}

void RecursiveReverse(struct node* head, struct node** headptr)
{
  if (head->next == NULL)
  {
    *headptr = head;
    return;
  }
  RecursiveReverse(head->next, headptr);
  struct node* previous = head->next;
  previous->next = head;
  head->next = NULL;
}

void Reverse(struct node** headptr)
{
  struct node* current = *headptr;
  struct node* previous = NULL;
  struct node* next;

  while( current != NULL ) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  *headptr = previous;
}


void Insert(int x, struct node** headptr)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->next = *headptr;
  *headptr = temp;
}

void Remove(int position, struct node** headptr)
{
  int i;
  struct node* current = *headptr;
  struct node* previous;
  if(position == 0)
  {
    previous = *headptr;
    *headptr = (*headptr)->next;
    free(previous);
    return;
  }
  for(i=0; i < position;i++)
  {
    previous = current;
    current = current->next;
  }
  previous->next = current->next;
  free(current);

}

void InsertAt(int data, int position, struct node** headptr)
{
  int i;
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  struct node* otherTemp = *headptr;
  temp->data = data;
  temp->next = NULL;
  if(position == 0)
  {
    temp->next = *headptr;
    *headptr = temp;
    return;
  }
  for( i=0; i < position-1; i++ )
  {
    otherTemp = otherTemp->next;
  }
  temp->next = otherTemp->next;
  otherTemp->next = temp;
}

void Print(struct node* head)
{
  printf("List is: ");
  printf("[");
  while(head != NULL)
  {
    printf("%d,", head->data);
    /*printf("(%p,%p)", head,head->next);*/
    head = head->next;
  }
  printf("]");
  printf("\n");
}
