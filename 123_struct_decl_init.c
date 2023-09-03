#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct date {
    int month;
    int day;
    int year;
};

struct employee {
    char name[MAX_NAME_LENGTH];
    struct date hireDate;
    float salary;
};

/* Function to set a newline char to NULL */
void newline_to_null(char* strPtr)
{
    int i = -1;
    while (strPtr[++i] != '\n');
    strPtr[i] = '\0';
}

/* Function to input & set data for an employee struct */
int get_set_input_for(struct employee *empl_struct_name)
{
    // get & store empl struct name
    printf("Enter the employee name: ");
    fgets(empl_struct_name->name, MAX_NAME_LENGTH, stdin);
    printf("\n");
    newline_to_null(empl_struct_name->name);
    
    // get & store hire date
    char date_str[MAX_NAME_LENGTH];
    printf("Enter the hire date (mm/dd/yyyy): ");
    fgets(date_str, MAX_NAME_LENGTH, stdin);
    printf("\n");
    newline_to_null(date_str);

    // tokenize date str & store in hireDate struct
    char *token = strtok(date_str, "/");    // split by '/'
    empl_struct_name->hireDate.month = atoi(token);
    token = strtok(NULL, "/");
    empl_struct_name->hireDate.day = atoi(token);
    token = strtok(NULL, "/");
    empl_struct_name->hireDate.year = atoi(token);

    // get & store salary
    printf("Enter the salary (in thousands of dollars): ");
    scanf("%f", &empl_struct_name->salary);
    getchar();
    printf("\n");

    return 0;
}

int main()
{
    // initialize empl1
    struct employee empl1;
    strncpy(empl1.name, "Justin Triana", MAX_NAME_LENGTH);
    empl1.name[MAX_NAME_LENGTH - 1] = '\0';
    empl1.hireDate = (struct date) { 3, 26, 2015 };
    empl1.salary = 50.0;

    // get input for empl2
    struct employee empl2;
    get_set_input_for(&empl2);

    // initialize empl3
    struct employee empl3 = { "Maria Steinberger", {10, 25, 2020}, 5.5 };

    // print empl struct data
    printf("Employee 1 info:\nName: %s, Hire date: %d/%d/%d, Salary: $%.2fk\n", empl1.name, empl1.hireDate.month, empl1.hireDate.day, empl1.hireDate.year, empl1.salary);
    printf("Employee 2 info:\nName: %s, Hire date: %d/%d/%d, Salary: $%.2fk\n", empl2.name, empl2.hireDate.month, empl2.hireDate.day, empl2.hireDate.year, empl2.salary);
    printf("Employee 3 info:\nName: %s, Hire date: %d/%d/%d, Salary: $%.2fk\n", empl3.name, empl3.hireDate.month, empl3.hireDate.day, empl3.hireDate.year, empl3.salary);

    return 0;
}
