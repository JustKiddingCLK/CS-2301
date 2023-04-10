Summary:
This is a C program that reads a file containing financial transactions and performs the overall revenue and balance.
Task 1 will call for overall_revenue() and calculates the total revenue for all sales in the input file.
Task 2 will call for balance() and calculate the balance of an account based on transactions in the input file.
Task 3 will call for the new function tally(); in money.c and add up the number of items sold in the input file and writes the results into an output file from the "output file" command line argument. The output file will be opened and edited it either "o" (overwrite mode) or "a" (append mode).

How to Run:
First, run the make command (mingw32-make). This will compile all the files (coffee_shop.c, money.c, register.h) and creates a execution file named sales.exe.
By inputting the parameters:
./sales.exe "task option" "input file" "output file" "file editing mode" "item ID", it will run the specified task.

Issues:
An issue I had was trying to get the outputs to be written/appended into the output file. I used an online resource (GeeksforGeeks) to find strcmp which compares the output mode to either "a" or "o". If they are equal, the difference will be 0. This is the way I was able to pass through the if statement to see which "file editing mode" was chosen.

Sources:

GeeksForGeeks: https://www.geeksforgeeks.org/strcmp-in-c/
					 