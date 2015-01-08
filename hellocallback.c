#include<stdio.h>

void Hello(){
  printf("Hello world\n");
}

void B(void (*ptr)())
{
  ptr();
}

int main(void)
{
  void (*ptr)() = Hello;
  B(ptr);
}
