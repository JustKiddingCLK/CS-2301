#include <stdio.h>

void get_totals(int month_data[][7], int num_items, int num_months)
{
    FILE* f = fopen("Total_sales.txt", "w");
    fprintf(f, "Item\tSales\n");
    for (int i = 1; i < num_items; i++)
    {
        int total_sales = 0;
        for (int j = 1; j < num_months; j++)
        {
            total_sales += month_data[i][j];
        }
        fprintf(f, "%2d\t%d\n", i, total_sales);
    }
    fclose(f);
}


void get_profits(int month_data[][7], int num_items, int num_months, float money[][2])
{
    FILE* f = fopen("Profits.txt", "w");
    fprintf(f, "Item\t#\tIncome\tCost\tProfit\n");
    for (int i = 0; i < num_items; i++)
    {
        int total_sales = 0;
        float total_income = 0.0;
        float total_cost = 0.0;
        for (int j = 1; j < num_months; j++)
        {
            total_sales += month_data[i][j];
        }
            total_income = total_sales * money[i][0];
            total_cost = total_sales * money[i][1];
            float profit = total_income - total_cost;
            fprintf(f, "%2d\t%d\t%6.2f\t%6.2f\t%6.2f\n", i, total_sales, total_income, total_cost, profit);
    }
    fclose(f);
}

void top_earner(int month_data[][7], int num_items, int num_months, float money[][2])
{
    float profits[num_items];
    int total_sales[num_items];
    
    for (int i = 0; i < num_items; i++)
    {
        total_sales[i] = 0.0;
        for (int j = 1; j < num_months; j++)
        {
            total_sales[i] += month_data[i][j];
        }
        profits[i] = (money[i][0] - money[i][1]) * total_sales[i];
    }
    int sorted_items[num_items];
    for (int i = 0; i < num_items; i++)
    {
        sorted_items[i] = i;
    }
    for (int i = 0; i < num_items - 1; i++)
    {
        for (int j = i + 1; j < num_items; j++)
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
