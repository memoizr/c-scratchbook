#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{

  return (*(int*)a - *(int*)b);
}

int main(void) {
  int i, size, array[] = {-31,45,-1, 0, -6,78, 4,-2};
  size = sizeof(array)/sizeof(int);
  qsort(array,size,sizeof(int), compare);
  for (i=0;i<size;i++) {
    printf("%d,",array[i]);
  }
  printf("\n");
}

