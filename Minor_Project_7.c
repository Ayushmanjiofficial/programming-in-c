#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 100
#define NAME_LEN 50
#define FOOD_NAME_LEN 50

typedef struct {
    int orderNumber;
    char customerName[NAME_LEN];
    char foodItem[FOOD_NAME_LEN];
    float price;
} Order;

Order orders[MAX_ORDERS];
int numOrders = 0;

void addOrder() {
    if (numOrders >= MAX_ORDERS) {
        printf("Order list is full!\n");
        return;
    }
    Order newOrder;
    printf("Enter order number: ");
    scanf("%d", &newOrder.orderNumber);
    printf("Enter customer name: ");
    scanf("%s", newOrder.customerName);
    printf("Enter food item: ");
    scanf("%s", newOrder.foodItem);
    printf("Enter price: ");
    scanf("%f", &newOrder.price);
    orders[numOrders++] = newOrder;
    printf("Order added successfully!\n");
}

void displayOrders() {
    if (numOrders == 0) {
        printf("No orders to display!\n");
        return;
    }
    for (int i = 0; i < numOrders; i++) {
        printf("Order Number: %d\n", orders[i].orderNumber);
        printf("Customer Name: %s\n", orders[i].customerName);
        printf("Food Item: %s\n", orders[i].foodItem);
        printf("Price: %.2f\n", orders[i].price);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nFood Order Management System\n");
        printf("1. Add Order\n");
        printf("2. Display Orders\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addOrder();
                break;
            case 2:
                displayOrders();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
