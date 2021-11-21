#include <stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/* void swap_c(const int *a, const int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
} */

int main()
{
    /* int a = 2;
    int b = 3;
    printf("%p,%p\n", &a, &b);
    swap(&a, &b);
    printf("%d,%d\n", a, b);
    getchar(); */
    
    struct test{
        short a:1;
        short b:1;
    };
    printf("ret:%d\n",sizeof(struct test));
    return 0;
}