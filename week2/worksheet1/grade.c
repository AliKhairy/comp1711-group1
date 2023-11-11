#include <stdio.h>
int main() {
    int choice;
    printf("Menu:\n1. Option A\n2. Option B\n3. Option C\n4. Option D\n5. Option E\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
     {
        case 1:
        printf("You selected Option A.\n");
        break;
        case 2:
        printf("You selected Option B.\n");
        break;
        case 3:
        printf("You selected Option C.\n");
        break;
        case 4:
        printf("You selected Option D.\n");
        break;
        case 5:
        printf("You selected Option E.\n");
        break;
        default:
        printf("Invalid choice.\n");
        }
        return 0;}