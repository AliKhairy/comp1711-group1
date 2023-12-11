#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
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


int main() {
    char steps_str[100];
    char line_buffer[100];
    char filename[100];
    int count = 0;
    int a = 0;
    char b[1000];

    FitnessData data[1000];
    FILE *input;

    printf("Input filename: ");
    scanf("%s", filename);
    input = fopen(filename, "r");
    if (input == NULL)
    {
    printf("Error: File could not be opened\n");
    return 1;
    }

    
    while (fgets(line_buffer, 100, input) != NULL)
    {
    tokeniseRecord(line_buffer, ",", data[count].date, data[count].time, steps_str);
    data[count].steps = atoi(steps_str);

    //check if data is invalid
    if (data[count].date[4] != '-' || data[count].time[2] != ':' || data[count].steps < 10)
    {
        printf("Error: Invalid data.\n");
        printf("%s %s %d\n", data[count].date, data[count].time, data[count].steps);
        return 1;
    }
    
    count++;
    }
    fclose(input);
    char *arr[count+1];
    for (int i = 0; i < count; i++){
        arr[i] = strdup(data[i].time);
    }
        
    
     for (int i = 0; i < count; ++i) 
        {
            for (int j = i + 1; j < count; ++j) 
            {
                if (data[i].steps < data[j].steps) 
                {
                    a = data[i].steps;
                    data[i].steps = data[j].steps;
                    data[j].steps = a;

                    strcpy(b, arr[i]);
                    strcpy(arr[i], arr[j]);
                    strcpy(arr[j], b);
                }
            }
        }
        char newFilename[100];
        strcpy(newFilename, filename);
        strcat(newFilename, ".tsv");
        
        FILE *output = fopen(newFilename, "w");
        if (output == NULL) {
            printf("Error: Unable to create file\n");
            return 1;
        }
        
        for (int i = 0; i < count; ++i) 
        {
            fprintf(output, "%s\t%s\t%d\n", data[i].date, arr[i], data[i].steps);
        }
        
        fclose(output);
        return 0;
}