The function float* readCost allocates memory for the array using malloc function and then opens the file "Costs.txt" using fopen and reads the Cost column of the Costs.txt file into an array and returns a pointer to the array. Then, it closes the file and returns a pointer to the array.

The function float* readIncome works similarly to the readCosts function, but it reads the second column of the Costs.txt file into the income array instead of the third column. It also returns the income array, which contains the income values for each item.

Run by first using the make command. Then run ./analysis.exe "data.txt" "data.txt".