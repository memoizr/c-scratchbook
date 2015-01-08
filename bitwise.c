#include<stdio.h>

int main(void)
{
  unsigned int a = 0x00;

  printf("%x\n",a);
  a ^= 1 << 31;
  printf("%x\n",a);
}
