#include <stdio.h>
#include <stdlib.h>
#include "data_functions.h"

/********************************************************
 * getSum(float x[], int size)
 * 
 * Calculates the sum of the first n values in x, where
 * n== size
 * 
 * Input    type    Description
 * x        float[] array of values
 * size     int     number of values to add together
 * 
 * Returns:
 *  The total of x[0] through x[size-1]
*********************************************************/
float getSum(float x[], int size)
{
    float SUM = 0;
    
    for(int i=0;i<size;i++)
    {
        SUM = SUM + x[i];
    }
    return SUM;
}

float* read_data (int num_items)
{
    float array[num_items];
    FILE* f = fopen("data.txt","r");
    if (f != NULL)
    {
        for (int i = 0; i < num_items; i++)
        {
            fscanf(f, "%f", &array[i]);       
        }
        float sum = getSum(array, num_items);
    }
    else
    {
        puts("Missing file\n");
    }
}