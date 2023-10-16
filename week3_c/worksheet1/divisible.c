#include <stdio.h>
int main() {
    int num;
    printf("what num? ");
    scanf("%d", &num);
    if (num % 4 == 0 && num % 5 == 0)
    {
        printf("%d is divisible by both 4 and 5\n", num);
    }
    else
    {
        printf("%d isn't divisible by both 4 and 5\n", num);
    }
    return 0;
    
}