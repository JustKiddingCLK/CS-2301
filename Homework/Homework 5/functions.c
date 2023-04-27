#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void get_totals(int rows, int cols, int month_data[][cols])
{
    FILE* f = fopen("Total_sales.txt", "w");
    fprintf(f, "Item\tSales\n");
    for (int i = 1; i < rows; i++)
    {
        int total_sales = 0;
        for (int j = 1; j < 7; j++)
        {
            total_sales += month_data[i][j];
        }
        fprintf(f, "%2d\t%d\n", i, total_sales);
    }
    fclose(f);
}


void get_profits(int rows, int cols, int month_data[][cols], float income[], float cost[])
{
    FILE* f = fopen("Profits.txt", "w");
    fprintf(f, "Item\t#\tIncome\tCost\tProfit\n");
    for (int i = 0; i < 51; i++)
    {
        int total_sales = 0;
        float total_income = 0.0;
        float total_cost = 0.0;
        for (int j = 1; j < cols; j++)
        {
            total_sales += month_data[i][j];
        }
            total_income = total_sales * income[i];
            total_cost = total_sales * cost[i];
            float profit = total_income - total_cost;
            fprintf(f, "%2d\t%d\t%6.2f\t%6.2f\t%6.2f\n", i, total_sales, total_income, total_cost, profit);
    }
    fclose(f);
}

void top_earner(int rows, int cols, int month_data[][cols], float income[], float cost[])
{
    float profits[rows];
    int total_sales[rows];
    
    for (int i = 0; i < rows; i++)
    {
        total_sales[i] = 0.0;
        for (int j = 1; j < cols; j++)
        {
            total_sales[i] += month_data[i][j];
        }
        profits[i] = (income[i] - cost[i]) * total_sales[i];
    }
    int sorted_items[rows];
    for (int i = 1; i < rows; i++)
    {
        sorted_items[i] = i;
    }
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (profits[sorted_items[i]] < profits[sorted_items[j]])
            {
                int temp = sorted_items[i];
                sorted_items[i] = sorted_items[j];
                sorted_items[j] = temp;

                int temp_total = total_sales[i];
                total_sales[i] = total_sales[j];
                total_sales[j] = temp_total;
            }
        }
    }
    FILE* f = fopen("Top_earners.txt", "w");
    fprintf(f, "Item\t#\tProfit\n");
    for (int i = 0; i < 10; i++)
    {
        fprintf(f, "%3d\t%2d\t%7.2f\n", sorted_items[i], total_sales[i], profits[sorted_items[i]]);
    }
    fclose(f);
}

float* readCosts(int numItems)
{
    float* costs = malloc(numItems * sizeof(float));
    if (costs == NULL) {
        printf("Error!");
    }
    FILE* f = fopen("Costs.txt", "r");
    if (f == NULL) {
        printf("Error!");
    }
    int item;
    float purchase, cost;
    while (fscanf(f, "%d %f %f", &item, &purchase, &cost) == 3)
    {
        costs[item] = cost;
    }
    fclose(f);
    return costs;
}

float* readIncome(int numItems)
{
    float* income = malloc(numItems * sizeof(float));
    if (income == NULL)
    {
        printf("Error!");
    }
    FILE* f = fopen("Costs.txt", "r");
    if (f == NULL)
    {
        printf("Error!");
    }
    int item;
    float purchase, cost;
    while (fscanf(f, "%d %f %f", &item, &purchase, &cost) == 3)
    {
        income[item] = purchase;
    }
    fclose(f);
    return income;
}
