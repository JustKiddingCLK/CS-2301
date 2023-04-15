#include <stdio.h>

void get_totals(int month_data[][6], int num_items, int num_months)
{
    FILE* f = fopen("Total_sales.txt", "w");
    fprintf(f, "Item\tSales\n");
    //printf("%d\n", month_data[1][0]);

    for (int i = 0; i < num_items; i++)
    {
        int total_sales = 0;
        printf("New item:\n");
        for (int j = 1; j < num_months-1; j++)
        {
            printf("%d\n",month_data[i][j]);
            total_sales += month_data[i][j];
        }
        if (total_sales > 0)
        {
            fprintf(f, "%2d\t%d\n", i+1, total_sales);
        }
    }
    fclose(f);
}

void get_profits(int month_data[][6], int num_items, int num_months, float money[][2])
{
    FILE* f = fopen("Profits.txt", "w");
    fprintf(f, "Item\t#\tIncome\tCost\tProfit\n");
    for (int i = 0; i < num_items; i++)
    {
        int total_sales = 0;
        float total_income = 0.0;
        float total_cost = 0.0;
        for (int j = 1; j <= num_months; j++)
        {
            total_sales += month_data[i][j];
        }
        if (total_sales > 0)
        {
            total_income = total_sales * money[i][1];
            total_cost = total_sales * money[i][0];
            float profit = total_income - total_cost;
            fprintf(f, "%2d\t%d\t%.2f\t%.2f\t%.2f\n", i+1, total_sales, total_income, total_cost, profit);
        }
    }
    fclose(f);
}


void top_earner(int month_data[][7], int items, int num_months, float money[][2]){

    float profits[items];
    for (int i = 0; i < items; i++)
    {
        profits[i] = (money[i][0] - money[i][1]) * month_data[i][num_months];
    }
    int sorted_items[items];
    for (int i = 0; i < items; i++)
    {
        sorted_items[i] = i;
    }
    for (int i = 0; i < items - 1; i++)
    {
        for (int j = i + 1; j < items; j++)
        {
            if (profits[sorted_items[i]] < profits[sorted_items[j]])
            {
                int temp = sorted_items[i];
                sorted_items[i] = sorted_items[j];
                sorted_items[j] = temp;
            }
        }
    }
    FILE* f = fopen("Top_earners.txt", "w");
    fprintf(f, "Item   #   Profit\n");
    for (int i = 0; i < 10; i++)
    {
        fprintf(f, "%3d   %2d   %7.2f\n", sorted_items[i], month_data[sorted_items[i]][num_months], profits[sorted_items[i]]);
    }
    fclose(f);
}
