/*CH-230-A
a6_p5.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>

int main()
{
    unsigned char ch, a;
    scanf("%c", &ch); //rading the character
    int UC_Size = 0;
    printf("The decimal representation is: %d\n", ch);
    a = ch;
    while (a) //finding the size of the character
    {
        UC_Size++;
        a >>= 1;
    }
    printf("The backwards binary representation is: ");
    for (int i = 0; i < UC_Size; i++)  //iterating through bit by bit
        printf("%d", ((ch >> i) & 1)); //printing from right to left

    printf("\n");
    return 0;
}
