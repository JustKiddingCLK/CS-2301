#include <stdio.h>

int is_prime(int num) {
    if(num == 0 || num == 1)
    {
        return 0;
    }
    for(int i = 2; i <= num/2; i++)
    {
        if(num%i == 0) 
        {
            return 0;
        }
    }
    return 1;
}

int main() {
    int x;
    printf("How many prime numbers do you want? \n");
    scanf("%d", &x);
    int i = 0;
    int start = 2;
    while(i < x) {
        if(is_prime(start)) {
            printf("%d ", start);
            i++;
        }
        start++;
    }
    printf("\n");
    return 0;
}