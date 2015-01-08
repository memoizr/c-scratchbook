#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void Enqueue(int value);

struct node
{
  int data;
  struct node* next;
};

typedef struct node node;
node* front = NULL;
node* rear = NULL;

void Enqueue(int value)
{
  node* temp = (node*) malloc(sizeof(node));
  temp->data = value;
  temp->next = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = temp;
  }
  rear->next = temp;
  rear = temp;
}

void Denqueue()
{
  node* temp = front;
  if(front == NULL) return;
  if(front == rear) {
    front = rear = NULL;
  }
  front = temp->next;
  free(temp);
}

void print()
{
  node* temp = front;
  while(temp != NULL) {
    printf("%d, ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

bool IsEmpty()
{
  return front == NULL;
}

int Front(){
  if (front != NULL) {
    printf("front is: %d\n", front->data);
    return front->data;
  } else {
    printf("list is empty \n");
    return -1;
  }
}

int main(void)
{
  printf("%s\n",IsEmpty()? "true" : "false");
  Front();
  Enqueue(1);
  printf("%s\n",IsEmpty()? "true" : "false");
  Enqueue(2);
  Enqueue(3);
  Enqueue(4);
  Denqueue(4);
  Front();
  print();
  return 0;

}
