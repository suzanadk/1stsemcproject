#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct MCQ {
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char answer;
};


void createFile() {
	int numQuestions;
    char filename[100];
    FILE *file;
        printf("Enter the name of the File (Saved in.txt)");
        scanf("%s",filename);
        

        // Open the file in write mode ("w")
        file = fopen(filename, "w");

        if (file == NULL) {
            printf("Error opening file %s\n", filename);
        }

        // File creation successful
        printf("File %s created successfully.\n", filename);
        //filling of the quizes
    printf("Start filling the Quiz from here on:\n");

    // Prompt the user to enter the number of MCQs
    printf("Enter the number of MCQs: ");
    scanf("%d", &numQuestions);

    // Creating an array of structures to store questions  data
    struct MCQ mcqs[numQuestions];

    // Take input for each MCQ from the user
    for (int i = 0; i < numQuestions; i++) {
    	system("cls"); //clearing the screen 
        printf("\nQ.No.%d:\n", i + 1);

        printf("Enter the question: ");
        getchar(); // in order to clear the input buffer
        fgets(mcqs[i].question, sizeof(mcqs[i].question), stdin);

        printf("Enter option A: ");
        fgets(mcqs[i].optionA, sizeof(mcqs[i].optionA), stdin);

        printf("Enter option B: ");
        fgets(mcqs[i].optionB, sizeof(mcqs[i].optionB), stdin);

        printf("Enter option C: ");
        fgets(mcqs[i].optionC, sizeof(mcqs[i].optionC), stdin);

        printf("Enter option D: ");
        fgets(mcqs[i].optionD, sizeof(mcqs[i].optionD), stdin);

        printf("Enter the correct answer (A, B, C, or D): ");
        scanf(" %c", &mcqs[i].answer);
    }
    
    for (int i = 0; i < numQuestions; i++) {
        fprintf(file, "MCQ %d:\n", i + 1);
        fprintf(file, "Question: %s", mcqs[i].question);
        fprintf(file, "Option A: %s", mcqs[i].optionA);
        fprintf(file, "Option B: %s", mcqs[i].optionB);
        fprintf(file, "Option C: %s", mcqs[i].optionC);
        fprintf(file, "Option D: %s", mcqs[i].optionD);
        fprintf(file, "Correct Answer: %c\n\n", mcqs[i].answer);
    }

    // Close the file
    fclose(file);

    printf("Your question has been added sucessfully  stored in the file: '%s.txt'\n",filename);

        
        fclose(file);
		}

    


void playquiz() {
    char filename[100];
    FILE *file;

    while (1) {
    	
        printf("Enter the name of the file to open (or 'exit' to quit): ");
        scanf("%s",filename);
        if (strcmp(filename,"exit")==0){// asking the user if s/he wants to exit the program
        	printf("exiting thhe program.\n");
        	break;
		}
        file=fopen(filename,"r");

        // Open the file in read mode ("r")
        file = fopen(filename, "r");

        if (file == NULL) {
            printf("Error opening file %s or the file does not exist.\n", filename);
        }else{
		

        // File opened successfully, read and display its contents
        printf("File %s opened successfully.\n", filename);

        fclose(file);
    }
}
}

int main() {
    int choice;

    while (1) {
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

        if (choice == 1 || choice == 2) {
            break; // Exit the loop if a valid choice (1 or 2) is entered
        }
    }

    return 0;
}
