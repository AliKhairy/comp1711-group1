#include <stdio.h>
int strlen(char *string) {
    int i = 0; 
    while (*string != '\0') {
        string++;
        i++;
    }
    return i;

}

char concatStrings(char *str1, char *str2) {
    char cat;
    while (*str1 & *str2 != '\0' )
    {
        char cat = cat + *str1 + *str2;
        str1++;
        str2++;
    }
    return cat;
}

int main() {
    printf("%d\n", concatStrings("", ""));
}