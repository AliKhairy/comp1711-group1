#include <stdio.h>
int main() {
    float length;
    float width;
    
    printf("Length: ");
    scanf("%f", &length);
    printf("Width: ");
    scanf("%f", &width);

    float area = length*width;
    
    printf("Here is the area of the rectangle: %f\n", area);
}