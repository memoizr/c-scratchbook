#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 5

int A[MAX_SIZE];
int front = -1;
int back = -1;


void Enqueue(int value);
int Dequeue();
int Front();
bool IsEmpty();
bool IsFull();

void Enqueue(int value)
{
  if (((back+1) % MAX_SIZE) == front) {
    printf("max size reached\n");
    return;
  }
  if (IsEmpty()) {
    front = 0;
    back = 0;
  }
  else {
    back = (back + 1) % MAX_SIZE;
  }
  A[back] = value;
}

int Dequeue()
{
  if (IsEmpty()) {
    return -1;
  } else if (front == back) {
    front = back = -1;
  } else {
    back = (back -1) % MAX_SIZE;
  }
}

int Front()
{
  if (IsEmpty()) {
    return -1;
  } else {
    front = (front + 1) % MAX_SIZE;
  }
}

bool IsEmpty()
{
  if (back == -1 && front == -1) {
    return true;
  } else {
    return false;
  };
}

void print(){
  int i;
  if (back == -1) {
    return;
  }

  if (((back+1) % MAX_SIZE) == front) {
    for (i = back; i < MAX_SIZE; i++){
      printf("%d, ", A[i%MAX_SIZE]);
    }
  } else {
    for (i = front; i <= back; i++){
      printf("%d, ", A[i]);
    }
  }

  printf("\n");
}


int main(void)
{
  Enqueue(1);
  Enqueue(2);
  Enqueue(3);
  Enqueue(4);
  Enqueue(5);
  Front();
  Enqueue(6);
  print();
  return 0;

}

