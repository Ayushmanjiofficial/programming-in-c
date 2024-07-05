#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define NAME_LEN 50

typedef struct {
    int candidateID;
    char name[NAME_LEN];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int numCandidates = 0;

void addCandidate() {
    if (numCandidates >= MAX_CANDIDATES) {
        printf("Candidate list is full!\n");
        return;
    }
    Candidate newCandidate;
    printf("Enter candidate ID: ");
    scanf("%d", &newCandidate.candidateID);
    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;
    candidates[numCandidates++] = newCandidate;
    printf("Candidate added successfully!\n");
}

void castVote() {
    int candidateID;
    printf("Enter candidate ID to vote for: ");
    scanf("%d", &candidateID);
    for (int i = 0; i < numCandidates; i++) {
        if (candidates[i].candidateID == candidateID) {
            candidates[i].votes++;
            printf("Vote cast successfully!\n");
            return;
        }
    }
    printf("Candidate not found!\n");
}

void displayResults() {
    if (numCandidates == 0) {
        printf("No candidates to display!\n");
        return;
    }
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate ID: %d\n", candidates[i].candidateID);
        printf("Name: %s\n", candidates[i].name);
        printf("Votes: %d\n", candidates[i].votes);
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMini Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
