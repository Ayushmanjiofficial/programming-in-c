#include <stdio.h>

int main() {
    char operator;
    double first, second;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);

    switch (operator) {
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", first, second, first + second);
            break;
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", first, second, first - second);
            break;
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", first, second, first * second);
            break;
        case '/':
            if (second != 0.0)
                printf("%.1lf / %.1lf = %.1lf\n", first, second, first / second);
            else
                printf("Division by zero error!\n");
            break;
        default:
            printf("Error! Operator is not correct\n");
    }

    return 0;
}
