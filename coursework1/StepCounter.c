#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
FITNESS_DATA fitnessdata[1000];
char steps_str[100];
float sum;
float average;
int rounded_average;
int min;
int max;
int counter = 0;
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
    while (keepswitch == 1) {
    
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the data and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Exit\n");
    printf("Enter choice: ");
    char choice;
    scanf(" %c", &choice);   
    
    switch(choice)
    {
        case 'A':
        case 'a':
            printf("Input filename: ");
            scanf("%s", filename);
            input = fopen(filename, "r");
            if (input == NULL)
            {
            printf("Incorrectly named data file.\n");
            return 1;
            keepswitch = 0;
            }
            break;


        case 'B':
        case 'b':
            i = 0;
            while (fgets(line, 100, input) != NULL)
            {
            tokeniseRecord(line, ",", fitnessdata[i].date, fitnessdata[i].time, steps_str);
            fitnessdata[i].steps = atoi(steps_str);
            i++;
            }
            printf("Total records: %d\n", i);
            fclose(input);
            keepswitch = 1;
            break;

        case 'C':
        case 'c':
            min = fitnessdata[0].steps;
            for (counter = 0; counter < i; counter++) {
                if (fitnessdata[counter].steps < min) {
                    min = fitnessdata[counter].steps;
                }
            }
            for (counter = 0; counter < i; counter++) {
                if (fitnessdata[counter].steps == min) {
                    printf("Fewest steps: %s %s\n", fitnessdata[counter].date, fitnessdata[counter].time);
                }
            }
            keepswitch = 1;
            break;

            case 'd':
            case 'D':
            max = fitnessdata[0].steps;
            for (counter = 0; counter < i; counter++) {
                if (fitnessdata[counter].steps > max) {
                    max = fitnessdata[counter].steps;
                }
            }
            for (counter = 0; counter < i; counter++) {
                if (fitnessdata[counter].steps == max) {
                    printf("Largest steps: %s %s\n", fitnessdata[counter].date, fitnessdata[counter].time);
                }
            }
            keepswitch = 1;
            break;

            case 'e':
            case 'E':
                
                for (counter = 0; counter < i; counter++){
                    sum = sum + fitnessdata[counter].steps;
                }
                average = sum / i ;
                rounded_average = round(average);
                printf("Mean step count: %d\n", rounded_average);
                keepswitch = 1;
                break;

            case 'F':
            case 'f':
                {
                counter = 0;
                int longest_period_start = 0;
                int longest_period_end = 0;
                int current_period_start = 0;
                int current_period_end = 0;
                int longest_period_length = 0;
                int current_period_length = 0;
                
                while (counter < i)
                {
                    
                    
                    if (fitnessdata[counter].steps > 500) {
                        if (current_period_length == 0) {
                            current_period_start = counter;
                        }
                        current_period_end = counter;
                        current_period_length++;
                        
                        if (current_period_length > longest_period_length) {
                            longest_period_start = current_period_start;
                            longest_period_end = current_period_end;
                            longest_period_length = current_period_length;
                        }
                    } else {
                        current_period_length = 0;
                    }
                    counter++;
                }
                
                if (longest_period_length > 0) {
                    printf("Longest period start: %s %s\n", fitnessdata[longest_period_start].date, fitnessdata[longest_period_start].time);
                    printf("Longest period end: %s %s\n", fitnessdata[longest_period_end].date, fitnessdata[longest_period_end].time);
                } 
                keepswitch = 1;
                break;
                }
            case 'q':
            case 'Q':
                keepswitch = 0;
                break;
            default:
                printf("Please choose one of the options below\n");
                break;
    }
}
}








