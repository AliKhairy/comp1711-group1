#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *file = fopen("squares.dat", "w");
    if (file == NULL) {
        perror("");
        return 1;
    }
    int n;
    printf("Type a positive integer: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        fprintf(file, "%d\n", i*i);
    }

    fclose(file);
    return 0;
}