#include<stdio.h>

void move(int,int,int,int);
int main(void)
{
  int number;
  printf("Enter the number of disks: ");
  scanf("%d",&number);

  move(number,1, 3, 2);
  return 0;
}

void move(int count, int n1, int n3, int n2)
{
  if(count > 0)
  {
    move(count-1, n1,n2,n3);
    printf("Move disk %i from %i to %i.\n",n1,n2,n3);
    move(count-1,n2,n3,n1);
  }
}



