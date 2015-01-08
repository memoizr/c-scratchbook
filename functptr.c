#include<stdio.h>

int Add(int a, int b)
{
  int c;
  c = a + b;
  return c;
}

int main(void)
{
  int c;
  int (*p)(int, int);
  p = Add;
  c = p(3,2);
  printf("%d\n",Add(2,4));
  printf("%d\n",c);
  return 0;
}
