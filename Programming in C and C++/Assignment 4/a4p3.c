/*CH-230-A
a4_p3.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <float.h>
#include <math.h>
float geometric_mean(float arr[], int num)
{ // function for the geometric mean
    int i;
    float product = 1, gmean;
    for (i = 0; i < num; i++)
        product *= arr[i];
    gmean = pow(product, 1.0 / num);
    return gmean;
}

float highest(float arr[], int num)
{ //function for the highest value in the array
    int i;
    float highest = FLT_MIN;

    for (i = 0; i < num; i++)
        if (arr[i] > highest)
            highest = arr[i];

    return highest;
}

float lowest(float arr[], int num)
{ ///function for the lowest value in the array
    int i;
    float lowest = FLT_MAX;
    for (i = 0; i < num; i++)
        if (arr[i] < lowest)
            lowest = arr[i];

    return lowest;
}

float sum(float arr[], int num)
{ //function for the sum of the values
    float sum = 0;
    int i;
    for (i = 0; i < num; i++)
        sum += arr[i];
    return sum;
}

float v[20], x;
int i, n;
char c;
int main()
{
    for (i = 0; i < 15; i++)
    {
        scanf("%f", &x);
        if (x > 0)

        {
            v[n++] = x;
        }

        else
            break;
    }
    scanf("\n%c", &c);
    switch (c) //switch instruction
    {
    case 'm':
        printf("Geometric mean of the array:%f\n", geometric_mean(v, n));
        break;
    case 'h':
        printf("Highest number in the array:%f\n", highest(v, n));
        break;
    case 'l':
        printf("Lowest number in the array:%f\n", lowest(v, n));
        break;
    case 's':
        printf("Sum of all elements in the array:%f\n", sum(v, n));
        break;
    default:
        break;
    }

    return 0;
}