Line 12:
Changed if (i = 9) to if (i == 9)
With one equal sign, it is trying to make the variable "i" equal to 9. However, we want to look to see if "i" IS EQUAL to 9.

Line 21:
Changed int sum = getSum(array, 13) to int sum = getSum(array, 10)
The array size was created to only have a size of 10. Inputting 13 will cause an error because the array being called is bigger than the one created.