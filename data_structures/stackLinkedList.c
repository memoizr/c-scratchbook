#include<stdio.h>
#include<stdlib.h>

struct node
{
  int value;
  struct node* next;
};

typedef struct node node;

node* top = NULL;

void Push(int value)
{
  node* temp = (node*)malloc(sizeof(node*));
  temp->value = value;
  temp->next = top;
  top = temp;
}

int Pop()
{
  if(top == NULL) return;
  node* temp = top;
  top = top->next;
  free(temp);
}

int Print()
{
  node* head = top;
  while(head != NULL)
  {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}


int main(void)
{
  Push(5);
  Push(6);
  Push(7);
  Print();
  Pop();
  Push(8);
  Print();

}
