The code functions.c will write three different files:
"Total_sales.txt", "Profits.txt", and "Top_earners.txt".

The get_totals function takes the two-dimensional array month_data and calculates the total sales for each item across all months and writes the item number and total sales to "Total_sales.txt".

The get_profits function also takes the month_data array and also takes the two-dimensional array money that contains the income and cost for each item. It calculates the income, cost, and profit for each item and writes it into "Profits.txt".

The top_earner function the month_data and money arrays and calculates the profit for each item. It then sorts the items in descending order by profit and writes the top 10 earners to "Top_earners.txt".

To run it, run the make command (mingw32-make). Then run ./analysis.exe