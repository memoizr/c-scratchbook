#include<stdio.h>
#include<string.h>

void Reverse(char* c, int i)
{
}

int main(void)
{
  char c[51];
  printf("enter a string");
  scanf("%s",c);
  Reverse(c, strlen(c));
  printf("Output = %s", c);

}
