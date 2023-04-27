#include <stdio.h>
#include <stdlib.h>
#include "matrix_math.h"

struct matrix* readMatrix(char* filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error: Unable to open file.\n");
        return NULL;
    }
    struct matrix *A = (struct matrix*)malloc(sizeof(struct matrix));
    fscanf(fp, "%d", &A->size);
    A->data = (float*)malloc(sizeof(float)*A->size);
    for(int i=0; i<A->size; i++){
        fscanf(fp, "%f", &A->data[i]);
    }
    fclose(fp);
    return A;
}

int deleteMatrix(struct matrix* A)
{
    free(A->data);
    free(A);
    return 0;
}

struct matrix* addition(struct matrix* A, struct matrix* B)
{
    // Check if matrices are compatible for addition
    if(A->size != B->size)
    {
        printf("This math cannot be performed.\n");
        return NULL;
    }
    struct matrix *result = (struct matrix*)malloc(sizeof(struct matrix));
    result->size = A->size;
    result->data = (float*)malloc(sizeof(float)*result->size);
    for(int i=0; i<result->size; i++)
    {
        result->data[i] = A->data[i] + B->data[i];
    }
    return result;
}

struct matrix* subtraction(struct matrix* A, struct matrix* B)
{
    // Check if matrices are compatible for subtraction
    if(A->size != B->size){
        printf("This math cannot be performed.\n");
        return NULL;
    }
    struct matrix *result = (struct matrix*)malloc(sizeof(struct matrix));
    result->size = A->size;
    result->data = (float*)malloc(sizeof(float)*result->size);
    for(int i=0; i<result->size; i++){
        result->data[i] = A->data[i] - B->data[i];
    }
    return result;
}