/*
Pseudocode for Homework 1 Part 1

Initialize variables

Prompt user for value
Get value from terminal and store in variable

Loop over all numbers  (x) less than the specified value (v)
    if the v/x is a whole number (hint, use the % operator which returns the remainder of a/b)
        then the value is not prime
        print "This value is not a prime number" to the terminal
        Exit the loop

If v/x was never a whole number
    print "This value is a prime number" to the terminal
*/
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    int x;
    bool prime;
    printf("Please enter a value: ");
    scanf("%d",&x);
    for(int i = 2; i <= x-1; i++)
    {
        if(x%i == 0)
        {
            prime = false;
            break;
        }
        else if(x%i != 0)
        {
            prime = true;
        }
    }
    if(prime == true)
    {
        printf("This value is a prime number \n");
    }
    else if(prime == false)
    {
        printf("This value is not a prime number \n");
    }
}