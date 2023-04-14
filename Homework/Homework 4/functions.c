#include <stdio.h>

void get_totals(int month_data[][7], int num_items, int num_months)
{
    FILE* f3 = fopen("Total_sales.txt", "w");
    fprintf(f3, "Item\tSales\n");
    for (int i = 0; i < num_items; i++)
    {
        int total_sales = 0;
        for (int j = 1; j <= num_months; j++)
        {
            total_sales += month_data[i][j];
        }
        fprintf(f3, "%02d\t%d\n", month_data[i][0], total_sales);
    }
    fclose(f3);
}

void get_profits(int month_data[][7], int num_items, int num_months, float money[][2])
{
    FILE* f = fopen("Profits.txt", "w");
    float total_income, total_cost, profit;
    fprintf(f, "Item\t#\tIncome\tCost\tProfit\n");
    for (int i = 1; i <= num_items; i++)
    {
        total_income = 0;
        total_cost = money[i][1];
        float profits[num_items];
        int max_index = i;
        for (int j = 1; j <= num_months; j++)
        {
            total_income += month_data[i][j] * money[i][1];
        }
        profit = (total_income - total_cost) * month_data[i][1];
        fprintf(f, "%02d\t%02d\t%.2f\t%.2f\t%.2f\n", i, month_data[i+1][0], total_income, total_cost, profit);
    }
    fclose(f);
}

void top_earner(int month_data[][7], int num_items, int num_months, float money[][2]) {
    FILE* f = fopen("Top_earners.txt", "w");
    float profits[num_items];
    for (int i = 1; i <= num_items; i++) {
        float total_income = 0, total_cost = money[i][0];
        for (int j = 1; j <= num_months; j++) {
            total_income += month_data[i][j] * money[i][1];
        }
        profits[i-1] = (total_income - total_cost) * month_data[i][1];
    }
    fprintf(f, "Item #\tProfit\n");
    for (int i = 0; i < num_items; i++) {
        int max_index = i;
        for (int j = i+1; j < num_items; j++) {
            if (profits[j] > profits[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            float temp_profit = profits[i];
            profits[i] = profits[max_index];
            profits[max_index] = temp_profit;
            int temp_item = month_data[i+1][0];
            month_data[i+1][0] = month_data[max_index+1][0];
            month_data[max_index+1][0] = temp_item;
        }
        if (i < 10) {
            fprintf(f, "%02d\t%02d\t%.2f\n", i+1, month_data[i+1][0], profits[i]);
        } else {
            break;
        }
    }
    fclose(f);
}
