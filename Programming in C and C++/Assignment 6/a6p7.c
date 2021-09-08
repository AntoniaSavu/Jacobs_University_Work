/*CH-230-A
a6_p7.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
void set3bits(unsigned char *ch, const int *a, const int *b, const int *c)
{
    *ch |= 1 << *a;
    *ch |= 1 << *b;
    *ch |= 1 << *c;
    //function which turns on 3 bits on the positions a, b and c
}
int main()
{
    unsigned char ch;
    int a, b, c;
    scanf("%c", &ch);
    scanf("%d %d %d", &a, &b, &c);
    int UC_Size = sizeof(ch) * 8 - 1;
    printf("The decimal representation is: %d\n", ch);
    printf("The binary representation is: ");
    for (int i = UC_Size; i >= 0; i--)

        printf("%d", ((ch >> i) & 1));

    printf("\n");
    set3bits(&ch, &a, &b, &c); //calling the function
    printf("After setting the bits: ");
    for (int i = UC_Size; i >= 0; i--)
        //going through the number bit by bit
        printf("%d", ((ch >> i) & 1)); //printing from left to right
    printf("\n");
    return 0;
}
