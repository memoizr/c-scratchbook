#include<stdio.h>

int compare(int a, int b)
{
  return a -b;
}
void BubbleSort(int *base, int size, int (*compare)(int,int))
{
  int i,j,tmp;
  for(i = 0; i < size; i++) {
    for(j = 0; j<size-1; j++) {

      if (compare(base[j],base[j+1]) > 0){
        tmp = base[j];
        base[j] = base[j+1];
        base[j+1] = tmp;
      }
    }
  }
}

int main(void)
{
  int array[] = {3,6,1,2,7,5,8};
  int size = sizeof(array)/sizeof(int);
  int i;
  for (i=0; i<size; i++) {
    printf("%d",array[i]);
  }
  printf("\n");
  BubbleSort(array, size, compare);
  for (i=0; i<size; i++) {
    printf("%d",array[i]);
  }
  printf("\n");
  return 0;
}


