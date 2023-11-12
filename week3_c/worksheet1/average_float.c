#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
    FILE *file = fopen("numbers.dat", "a+");
    if (file == NULL) {
        perror("");
        return 1;
        }
        int buffer_size = 100;
        char line_buffer[buffer_size];
        int counter = 0;
        float sum = 0;
        while (fgets(line_buffer, buffer_size, file) != NULL) {
            sum += atof(line_buffer);
            counter++;
        }
            if (line_buffer[strlen(line_buffer)-1] != '\n'){
            fprintf(file, "\n");
            }
            fprintf(file, "%f", sum / counter);
            fclose(file);
            return 0;
}