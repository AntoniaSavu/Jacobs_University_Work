/*CH-230-A
a6_p2.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#define LSB(x) (x & 1) //macro which acceses the rightmost bit

int main()
{
    unsigned char a;
    scanf("%c", &a); //reading the character
    printf("The decimal representation is: %d\n", (int)a);
    printf("The least significant bit is:%d", LSB(a)); //utilizing the macro

    return 0;
}
