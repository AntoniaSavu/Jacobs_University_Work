/*
CH-230-A
a3_p5.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
int i, n;
double array[101], temp, sum, average;

char c;
int main()
{
    scanf("%c", &c);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    { //using a loop to add the values in an array
        scanf("%lf", &temp);
        array[i] = temp;
        sum += array[i];
        average += array[i];
        //taking advantage of the loop by computing
        // the sum and average at the same time
    }
    average /= n;

    switch (c) //utilizing switch
    {
    case 's':
        printf("%lf", sum); //printing the sum for c='s'
        break;
    case 'p': // printing the array for c='p'
        for (i = 0; i < n; i++)
            printf("%lf ", array[i]);
        break;
    case 't': //printing the array as Farenheit for c='t'
        for (i = 0; i < n; i++)
            printf("%lf ", (array[i] * 9 / 5) + 32);
        break;
    default: //otherwise, printing average
        printf("%lf", average);
        break;
    }
}