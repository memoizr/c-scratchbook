#include<stdio.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int value)
{
  if(top == MAX_SIZE)
  {
    printf("Error: Stack Overflow\n");
    return;
  }
  A[++top] = value;
}

int GetTop()
{
  return A[top];
}

void Pop()
{
  if(top == -1)
  {
    printf("Error: Stack already empty\n");
    return;
  }
  top--;
}

void Print()
{
  int i;
  for(i=0;i<=top;i++)
  {
    printf("%d ",A[i]);
  }
  printf("\n");
}


int main(void)
{
  Push(2);
  Push(3);
  Push(4);
  Print();
  printf("%d \n", GetTop());
  Pop();
  printf("%d \n", GetTop());
}
