/*
CH-230-A
a2_p4.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    float a, b, h;
    scanf("%f%f%f", &a, &b, &h);
    // reading the length, width and height
    float square_area = a * a;
    printf("square area=%f\n", square_area);
    //computing and printing the square area
    float rectangle_area = a * b;
    printf("rectangle area=%f\n", rectangle_area);
    //computing and printing the rectangle area
    float triangle_area = a * h / 2;
    printf("triangle area=%f\n", triangle_area);
    //computing and printing the rectangle area
    float trapezoid_area = h * (a + b) / 2;
    printf("trapezoid area=%f\n", trapezoid_area);
    //computing and printing the trapezoid area

    return 0;
}