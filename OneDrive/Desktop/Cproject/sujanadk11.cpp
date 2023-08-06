#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createFile() {
    char filename[100];
    FILE *file;
    printf("there are no channges here:");

    while (1) {
        printf("Enter the name of the file (or 'exit' to quit): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline from fgets

        // Check if the user wants to exit the program (case-insensitive)
        if (strcasecmp(filename, "exit") == 0) {
    
            printf("Exiting the program.\n");
            break;
        }

        // Open the file in write mode ("w")
        file = fopen(filename, "w");

        if (file == NULL) {
            printf("Error opening file %s\n", filename);
            continue; // Skip this iteration and ask for a new filename
        }

        // File creation successful
        printf("File %s created successfully.\n", filename);
        fclose(file);
    }
}

void playquiz() {
    char filename[100];
    FILE *file;
    char ch;

    while (1) {
        printf("Enter the name of the file to open (or 'exit' to quit): ");
        fgets(filename, sizeof(filename), stdin);
        filename[strcspn(filename, "\n")] = '\0'; // Remove trailing newline from fgets

        // Check if the user wants to exit the program (case-insensitive)
        if (strcasecmp(filename, "exit") == 0) {
            printf("Exiting the program.\n");
            break;
        }

        // Open the file in read mode ("r")
        file = fopen(filename, "r");

        if (file == NULL) {
            printf("Error opening file %s or the file does not exist.\n", filename);
            continue; // Skip this iteration and ask for a new filename
        }

        // File opened successfully, read and display its contents
        printf("File %s opened successfully.\n", filename);

        fclose(file);
    }
}

int main() {
    int choice;

    printf("1. Create a new model\t2. Start a quiz competition\nEnter the number of your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createFile();
            break;
        case 2:
            playquiz();
            break;
        default:
            printf("Invalid option. Please choose 1 or 2.\n");
            break;
    }

    return 0;
}

