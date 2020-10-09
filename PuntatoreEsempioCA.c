#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pi;
    int a = 5,b;
    pi = &a;
    b=*pi;
    *pi=9;
    printf("a= %d  ",a);
    printf("    b=%d ",b);
    return 0;
}
