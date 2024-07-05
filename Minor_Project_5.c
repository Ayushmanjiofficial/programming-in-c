#include <stdio.h>

void convertLength() {
    float meters;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    printf("Length in kilometers: %.3f\n", meters / 1000);
    printf("Length in centimeters: %.3f\n", meters * 100);
    printf("Length in millimeters: %.3f\n", meters * 1000);
}

void convertWeight() {
    float kilograms;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);
    printf("Weight in grams: %.3f\n", kilograms * 1000);
    printf("Weight in milligrams: %.3f\n", kilograms * 1000000);
    printf("Weight in pounds: %.3f\n", kilograms * 2.20462);
}

void convertTemperature() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("Temperature in Fahrenheit: %.3f\n", (celsius * 9/5) + 32);
    printf("Temperature in Kelvin: %.3f\n", celsius + 273.15);
}

int main() {
    int choice;
    while (1) {
        printf("\nUnit Converter\n");
        printf("1. Convert Length\n");
        printf("2. Convert Weight\n");
        printf("3. Convert Temperature\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
