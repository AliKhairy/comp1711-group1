#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    char steps_str[100];
    char line_buffer[100];
    char filename[100];
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
    int i = 0;
    while (fgets(line_buffer, 100, input) != NULL)
    {
    tokeniseRecord(line_buffer, ",", data[i].date, data[i].time, steps_str);
    data[i].steps = atoi(steps_str);
    i++;
    }
    printf("%s %d", data[1].time, data[1].steps);
}