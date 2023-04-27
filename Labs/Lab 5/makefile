all: data_functions.o process_data.o
	gcc -Wall data_functions.o process_data.o -o processData.exe
data_functions.o: data_functions.c 
	gcc -c data_functions.c -o data_functions.o
process_data.o: process_data.c
	gcc -c process_data.c -o process_data.o
