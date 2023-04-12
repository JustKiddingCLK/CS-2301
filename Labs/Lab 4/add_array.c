#include <stdio.h>

int getSum(int[], int);
int getSumPtr(int *x, int size);

int main(void){
    // inizalized the array
    int array[10] = {1, 2, 3, 4};

    // put numbers in it
    for (int i=0; i < 10; i++){
        if (i == 9){
            array[i] = 12;
        }
        else{
            array[i] = i+1;
        }
    }

    // get sum
    int sum = getSum(array, 10);
    int sum1 = getSumPtr(array, 10);
    printf("The sum is %d\n", sum);
    printf("The sum is %d\n", sum1);
}

//takes an array
int getSum(int x[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + x[i];
    }
    return sum;
}

// takes a pointer to an array
int getSumPtr(int *x, int size){
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + x[i];
    }
    return sum;
}
