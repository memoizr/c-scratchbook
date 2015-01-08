#include<stdio.h>

void PrintHello(char* name)
{
  printf("Hello\n");
  printf("%s\n", name);
}

int main(void)
{
  void (*functPtr)(char*);
  functPtr = PrintHello;
  functPtr("hello there\0");
  return 0;
}

