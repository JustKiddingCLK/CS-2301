#include <stdio.h>

int add(int[], int);
int main(void){

    // create an array of 10 values
    int data[10];
    int value = 12;

    //  use a for loop to set the values to 12 to 21
    for(int i = 0; i < 10; i++)
    {
        data[i] = i+12;
    }

    //get the sum of all values in data
    int total = add(data, 10);

    // print total to the screen
    printf("%d",total);
}

/***********************************************
* add(int a[], int size)
* returns the sum of all values in a
* Input:
*   a: an array of size ints
*   size: the lenght of a
* Returns:
*   the sum of all values in a
************************************************/
int add(int a[], int size)
{   
    a[size];
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum = sum + a[i];
    }
    return sum;
}