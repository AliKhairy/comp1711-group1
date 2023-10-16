#include <stdio.h>
int main() {
    int mark;
    printf("what mark? ");
    scanf("%d", &mark);
    if (mark >= 70)
    {
        printf("distinction\n");
    }
    else if (mark >= 50)
    {
        printf("Pass\n");
    }
    else
    {
        printf("fail\n");
    }
    return 0;
}