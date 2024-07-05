#include <stdio.h>

int getFirstDayOfMonth(int year, int month) {
    int day = 1;
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

void printCalendar(int year, int month) {
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char *months[] = { "January", "February", "March", "April", "May", "June",
                       "July", "August", "September", "October", "November", "December" };
    
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[1] = 29;

    int firstDay = getFirstDayOfMonth(year, month);
    printf("\n  %s %d\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < firstDay; i++)
        printf("     ");

    for (int day = 1; day <= daysInMonth[month - 1]; day++) {
        printf("%5d", day);
        if (++firstDay > 6) {
            firstDay = 0;
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;
    printf("Enter month and year (MM YYYY): ");
    scanf("%d %d", &month, &year);
    printCalendar(year, month);
    return 0;
}
