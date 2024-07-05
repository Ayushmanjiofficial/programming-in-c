#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    int rollNumber;
    char name[NAME_LEN];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Cannot add more students!\n");
        return;
    }
    Student newStudent;
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter marks: ");
    scanf("%f", &newStudent.marks);
    students[numStudents++] = newStudent;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (numStudents == 0) {
        printf("No students to display!\n");
        return;
    }
    for (int i = 0; i < numStudents; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
// One problem in this code is, here not check the uncinus of primary key( roll no. )
