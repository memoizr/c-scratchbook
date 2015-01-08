#include<stdio.h>

void moveDisk(char* fp, char* tp)
{
  printf("moving disk from %c to %c\n", *fp, *tp);
}

void moveTower(int height, char* fromPole, char* toPole, char* withPole)
{
  if (height >= 1) {
    moveTower(height-1, fromPole, withPole, toPole);
    moveDisk(fromPole,toPole);
    moveTower(height-1, withPole, toPole, fromPole);
  }
}


int main(void)
{
  moveTower(3,"A","B","C");
  return 0;
}
