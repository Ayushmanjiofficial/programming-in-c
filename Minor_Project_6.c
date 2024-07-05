#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LEN 100

typedef struct {
    char task[TASK_LEN];
    int isCompleted;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask() {
    if (numTasks >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter task: ");
    getchar(); // consume newline left by previous input
    fgets(tasks[numTasks].task, TASK_LEN, stdin);
    tasks[numTasks].isCompleted = 0;
    numTasks++;
    printf("Task added successfully!\n");
}

void displayTasks() {
    if (numTasks == 0) {
        printf("No tasks to display!\n");
        return;
    }
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s [%s]\n", i + 1, tasks[i].task, tasks[i].isCompleted ? "Completed" : "Not Completed");
    }
}

void markTaskCompleted() {
    int taskNumber;
    printf("Enter task number to mark as completed: ");
    scanf("%d", &taskNumber);
    if (taskNumber < 1 || taskNumber > numTasks) {
        printf("Invalid task number!\n");
        return;
    }
    tasks[taskNumber - 1].isCompleted = 1;
    printf("Task marked as completed!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nVirtual Workplace Application\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Mark Task Completed\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
