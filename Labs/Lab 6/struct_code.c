#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct student
{
    char* firstName;
    char* lastName;
};

typedef struct student Student;

void print_student(Student thisStudent);

int main(void)
{
    // Open the file
    FILE* f1 = fopen("roster.txt", "r");

    // Read from file and store in array
    for (int i = 0; i < SIZE; i++)
    {
        Student class_list[SIZE];
        char* firstName = malloc(sizeof(char)*50);
        char* lastName = malloc(sizeof(char)*50);
        fscanf(f1, "%s %s", firstName, lastName);
        class_list[i].firstName = firstName;
        class_list[i].lastName = lastName;
        print_student(class_list[i]);
    }
    
    fclose(f1);
}

void print_student(Student thisStudent) {
    printf("%s ", thisStudent.firstName);
    printf("%s\n", thisStudent.lastName);
}
