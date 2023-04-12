#include <stdio.h>

int main(void){


    int i = 7;
    int j = 2;
    int *r = &j;
    j = j + 1;
    printf("The value behind r is %d\n", *r);

    int **n = &r;
    printf("n points to r which points to %d\n", **n);

}