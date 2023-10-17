#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Expense {
    char description[100];
    float amount;
};

struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense() {
    if (numExpenses < MAX_EXPENSES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]", expenses[numExpenses].description);
        printf("Enter expense amount: $");
        scanf("%f", &expenses[numExpenses].amount);
        numExpenses++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense list is full. Cannot add more expenses.\n");
    }
}

void displayExpenses() {
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
    } else {
        printf("Expenses:\n");
        for (int i = 0; i < numExpenses; i++) {
            printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
        }
    }
}

float calculateTotalExpenses() {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    int choice;

    do {
        printf("\n1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotalExpenses());
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
