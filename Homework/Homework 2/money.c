#include <stdio.h>

float overall_revenue(FILE *f1)
{
    float revenue = 0.0;
    float value;
    int i = 0;
    while(fscanf(f1,"%f", &value) != EOF)
    {
        if(i == 0 || i ==1)
        {
            
        }
        else if((i% 2)==1)
        {
            revenue += value;   
        }
        i = i + 1;
    }
    return revenue;
}

float balance(FILE *f1)
{
    float balance = 0.0;
    float value;
    int i = 0;
    while(fscanf(f1, "%f", &value) != EOF)
    {   
        if(i == 0 || i%2 == 0)
        {
            //continue;
        }
        else if(i%2 == 1)
        {
            balance += value;
        }
        i = i+ 1;
    }
    return balance;
}