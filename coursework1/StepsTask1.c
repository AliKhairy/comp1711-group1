#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
char line_buffer[100];
char record;
int i = 0;

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
    FILE *fitnessdata;
    fitnessdata = fopen("FitnessData_2023.csv", "r");
    if(fitnessdata == NULL) 
    {
        printf("error opening the file");
    }
    FITNESS_DATA data [] = {};

    while (fgets(line_buffer, 100, fitnessdata) != NULL) 
    {
        i++;
        record = ("%s", line_buffer);
        tokeniseRecord(record, ",", data->date, data->time, data->steps);
    }
    printf("Number of records in file: %d", i);
    
    for (i = 0; i < 3; i++) 
    {
        printf("date: %s\n", data[i]->date);
        printf("time: %s\n", fitness_data[i].time);
        printf("steps: %d\n", fitness_data[i].steps);
    }
}