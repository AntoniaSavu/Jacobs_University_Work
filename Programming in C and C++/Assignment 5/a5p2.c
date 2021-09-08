/*CH-230-A
a5_p2.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
void divby5(float arr[], int size)
{
    for (int i = 0; i < size; i++)
        arr[i] /= 5;
} //function to divide by 5
int main()
{
    float arr[] = {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};
    //declaring the given array
    printf("Before:\n");
    for (int i = 0; i < 6; i++)
        printf("%0.3f ", arr[i]); //printing the array
    printf("\n");
    printf("After:\n");
    divby5(arr, 6); //calling the function
    for (int i = 0; i < 6; i++)
        printf("%0.3f ", arr[i]); //printing the modified array
    printf("\n");

    return 0;
}