#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file = fopen("squares.dat", "r");
    if (file == NULL) {
        perror("");
        return 1;
        }
        char line_buffer[100];
        int counter = 0;
        float sum = 0;
        while (fgets(line_buffer, 100, file) != NULL) {
            sum += atoi(line_buffer);
            counter++;
            }
            printf("The average of the numbers is %.2f\n", sum / counter);
            fclose(file);
            return 0;
}