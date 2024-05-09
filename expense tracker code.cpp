#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORY_LEN 20

struct Expense {
    char category[MAX_CATEGORY_LEN];
    float amount;
};

struct Expense expenses[MAX_EXPENSES];
int numExp = 0;

void addExpense() {
    if (numExp >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Expense limit reached.\n");
        return;
    }

    struct Expense newExp;
    printf("Enter category of expense: ");
    scanf("%s", newExp.category);

    printf("Enter amount spent: ");
    scanf("%f", &newExp.amount);

    expenses[numExp++] = newExp;

    printf("Expense added successfully!\n");
}

void viewExpenses() {
    printf("\n--- All Expenses ---\n");
    for (int i = 0; i < numExp; i++) {
        printf("Category: %s, Amount: $%.2f\n", expenses[i].category, expenses[i].amount);
    }
    printf("\n");
}

float calculateTotalExpenses() {
    float total = 0.0;
    for (int i = 0; i < numExp; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    int choice;

    do {
        printf("Expense Tracker List\n");
        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotalExpenses());
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}