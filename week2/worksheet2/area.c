#include <stdio.h>
float circleArea(float x) {
    float area = 0;
    area = x*x*3.14159265359;
    return area;
} 
int main() {
    float area = circleArea(2.0);
    printf("%f\n", area);
}