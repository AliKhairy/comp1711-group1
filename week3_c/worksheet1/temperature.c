#include <stdio.h>
int main() {
    int temp;
    printf("Temperature? ");
    scanf("%d", &temp);
    if (temp >= -10 && temp <= 40)
    {
        printf("Temperature is between -10 and 40 degrees Celsius\n");
    }
    else
    {
        printf("Put a valid temperature between -10 and 40 degrees Celsius\n");
    }
    return 0;
}