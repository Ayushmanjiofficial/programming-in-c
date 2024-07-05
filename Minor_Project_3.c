#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define NAME_LEN 50

typedef struct {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
} Customer;

Customer customers[MAX_CUSTOMERS];
int numCustomers = 0;

void createAccount() {
    if (numCustomers >= MAX_CUSTOMERS) {
        printf("Bank is at full capacity!\n");
        return;
    }
    Customer newCustomer;
    printf("Enter account number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Enter name: ");
    scanf("%s", newCustomer.name);
    printf("Enter initial deposit: ");
    scanf("%f", &newCustomer.balance);
    customers[numCustomers++] = newCustomer;
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Withdrawal successful!\n");
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccount() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numCustomers; i++) {
        if (customers[i].accountNumber == accountNumber) {
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Name: %s\n", customers[i].name);
            printf("Balance: %.2f\n", customers[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nBanking Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayAccount();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
