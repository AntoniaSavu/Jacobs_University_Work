/*
CH-230-A
a3_p8.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
float sum(float array[], int n) //sum function
{
    float sum = 0;
    int i;
    for (i = 0; i < n; i++)
        sum += array[i];
    ///using a loop to add all the elements
    return sum;
}
float average(float array[], int n)
{
    float average = 0;
    int i;
    for (i = 0; i < 10; i++)
        average += array[i];
    average /= n; //using a loop to calculate de average
    return average;
}
float array[11];
int main()
{
    float x, sum1, average1;
    int i = 1, n = 0;
    while (i <= 10)
    {
        scanf("%f", &x);
        if (x == -99.0) //break condition
            break;
        else
            array[n++] = x; //adding elements into array
        i++;
    }
    sum1 = sum(array, n);         //calling the
    average1 = average(array, n); // two functions
    printf("Sum of the numbers entered: %f\n", sum1);
    printf("Average of the numbers entered: %f\n", average1);
}