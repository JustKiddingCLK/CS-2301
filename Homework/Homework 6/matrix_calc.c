#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        printf("Error!");
        return 1;
    }

    char* filename1 = argv[1];
    char* filename2 = argv[2];
    char type = argv[3][0];

    struct matrix* A = readMatrix(filename1);
    if (A == NULL) 
    {
        return 1;
    }

    struct matrix* B = readMatrix(filename2);
    if (B == NULL) 
    {
        deleteMatrix(A);
        return 1;
    }

    struct matrix* C;
    if (type == 'a') 
    {
        C = addition(A, B);
    } else if (type == 's') 
    {
        // Perform matrix subtraction
        C = subtraction(A, B);
    } 
    else 
    {
        deleteMatrix(A);
        deleteMatrix(B);
        return 1;
    }
    if (C == NULL) 
    {
        deleteMatrix(A);
        deleteMatrix(B);
        return 1;
    }

    // Print the result
    printf("Result:\n");
    for (int i = 0; i < C->size; i++)
    {
        printf("%.2f ", C->data[i]);
    }
    printf("\n");

    deleteMatrix(A);
    deleteMatrix(B);
    deleteMatrix(C);

    return 0;
}
