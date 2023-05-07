#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int numEmployees = 0;

void addEmployee() {
    if (numEmployees == MAX_EMPLOYEES) {
        printf("Maximum number of employees reached.\n");
        return;
    }

    struct Employee newEmployee;
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);

    printf("Enter employee name: ");
    scanf("%s", newEmployee.name);

    printf("Enter employee age: ");
    scanf("%d", &newEmployee.age);

    printf("Enter employee salary: ");
    scanf("%f", &newEmployee.salary);

    employees[numEmployees] = newEmployee;
    numEmployees++;

    printf("Employee added successfully.\n");
}

void displayEmployees() {
    if (numEmployees == 0) {
        printf("No employees found.\n");
        return;
    }

    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < numEmployees; i++) {
        struct Employee current = employees[i];
        printf("%d\t%s\t%d\t%.2f\n", current.id, current.name, current.age, current.salary);
    }
}

int findEmployeeById(int id) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1; // Employee not found
}

void removeEmployee() {
    int id;
    printf("Enter employee ID to remove: ");
    scanf("%d", &id);

    int index = findEmployeeById(id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    for (int i = index; i < numEmployees - 1; i++) {
        employees[i] = employees[i + 1];
    }

    numEmployees--;

    printf("Employee removed successfully.\n");
}

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Remove Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                removeEmployee();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
