#include<stdio.h>

void print(char c[])
{
    int i;
    while(c[i] != '\0') {
        printf("%c",*(c+i));
        i++;
    }
}

void printI(int c[], int size)
{
    int i;
    for(i = 0; i < size; i++) {
        printf("%d",c[i]);
    }
}

void arrayStuff()
{
    int C[2][3] = {{1,2,3},{3,4,3}};
    printf("%d\n", *C[0]);
}

int main(void)
{
    char *c = "hey there\n";
    arrayStuff();
    /*print(c);*/
    return 0;
}
