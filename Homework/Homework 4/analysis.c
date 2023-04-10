#include <stdio.h>

#define ITEMS 51

void get_totals(int[][7], int, int);

void get_profits(int[][7], int, int, float[][2]);

void top_earner(int[][7], int, int, float[][2]);


int main(void){
    // allocate arrays to store 6 months of data
    int month_data[ITEMS][7];
    float money[ITEMS][2];

    // initialize money and month_data to zeros
    for (int i = 0; i < 7; i ++){
        for (int j = 0; j < ITEMS; j++){
            month_data[j][i] = 0;
        }
    }
    for (int i = 0; i < ITEMS; i++){
        money[i][0] = 0;
        money[i][1] = 0;
    }

    int new_item;
    float cost;

    //loop over all months
    for (int i = 0; i < 6; i++){
        FILE* f1;
        // open sales file
        switch (i) {
            case 0:
                f1 = fopen("Jan_data.txt", "r");
                break;
            case 1:
                f1 = fopen("Feb_data.txt", "r");
                break;
            case 2:
                f1 = fopen("Mar_data.txt", "r");
                break;
            case 3:
                f1 = fopen("Apr_data.txt", "r");
                break;
            case 4:
                f1 = fopen("May_data.txt", "r");
                break;
            case 5:
                f1 = fopen("Jun_data.txt", "r");
                break;
        } // end switch

        // load sales data


        while(fscanf(f1, "%d %f", &new_item, &cost) > 0){
            month_data[new_item][i+1] = month_data[new_item][i+1] + 1;
            month_data[new_item][0] = new_item;
        }
        fclose(f1);

    } // end loop over months

    // load sales data
    FILE* f2 = fopen("Costs.txt", "r");
    float purchase;

    while(fscanf(f2, "%i %f %f", &new_item, &purchase, &cost) > 0)
    {
        money[new_item][0] = purchase;
        money[new_item][1] = cost;
    }
    fclose(f2);

    get_totals(month_data, ITEMS, 7);
    get_profits(month_data, ITEMS, 7, money);

}

void get_totals(int month_data[][7], int num_items, int num_months)
{
    FILE* f = fopen("Total_sales.txt", "w");
    fprintf(f, "Item Sales\n");
    for (int i = 0; i < num_items; i++)
    {
        int total_sales = 0;
        for (int j = 1; j <= num_months; j++)
        {
            total_sales += month_data[i][j];
        }
        fprintf(f, "%02d %d\n", month_data[i][0], total_sales);
    }
    fclose(f);
}

void get_profits(int month_data[][7], int num_items, int num_months, float money[][2])
{
    FILE* f = fopen("Profits.txt", "w");
    fprintf(f, "Item # Income Cost Profit\n");
    for (int i = 0; i < num_items; i++) {
        int total_sales = 0;
        float total_income = 0, total_cost = 0, profit = 0;
        for (int j = 1; j <= num_months; j++)
        {
            total_sales += month_data[i][j];
        }
        total_income = total_sales * money[i][1];
        total_cost = total_sales * money[i][0];
        profit = total_income - total_cost;
        fprintf(f, "%02d %.2f %.2f %.2f\n", month_data[i][0], total_income, total_cost, profit);
    }
    fclose(f);
}
