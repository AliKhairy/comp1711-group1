#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
char choice;
int i = 0;
char line[100];
FILE *input;
int keepswitch = 1;
// Global variables for filename and FITNESS_DATA array
char filename[50];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {
    while (keepswitch != 0) {
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit\n");
    printf("Enter choice: ");
    choice = getchar();
    while (getchar() != '\n');
    
    
    switch(choice)
    {
        case 'A':
        case 'a':
            
            printf("Input filename: ");
            scanf("%s", filename);
            input = fopen(filename, "r");
            if (input == NULL)
            {
            printf("Error: File could not be opened\n");
            return 1;
            }
            else {
                printf("File successfully loaded.\n");
            }
            break;


        case 'B':
        case 'b':
            i = 0;
            while(fgets(line, 100, input) != NULL) {
                i++;
            }
            printf("Total records: %d\n", i);
            fclose(input);
            keepswitch = 0;
            break;
    
    }
    }
}









