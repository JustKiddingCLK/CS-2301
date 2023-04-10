Write a document called README.txt that summarizes your program, how to run it, and
detailing any problems that you had. If you used any outside resources for this assignment,
be sure to cite your sources and explain in detail how the code works. 

Summary:
The Financial Analysis Program is a C program that reads a file containing financial transactions and performs the overall revenue and balance. The program prompts the user to choose which calculation to perform: overall revenue or balance. It then prompts the user to input the name of the financial file. The program then opens the file and calls either the overall_revenue() or balance() function from the register.h. The header file contains the function prototypes for overall_revenue() and balance(). In my money.c source file, I have two the two functions. Each function takes a file pointer as an input and returns a float value as the output. The overall_revenue() function first skips the first line and then reads the second column, adding all of the numbers up. The function balance() does the same except it includes the first row.

How to Run:
First, run the make command (mingw32-make). This will compile all the files (coffee_shop.c, money.c, register.h) and creates a execution file named run.exe. Then, run .\run.exe to run the executable.

Issues:
Some issues that I had to go through was trying to get the program to ignore the first row and first column. I did not work with anyone. 