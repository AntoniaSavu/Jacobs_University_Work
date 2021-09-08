/*
CH-230-A
a2_p7.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
    int i = 8;
    while (i >= 4)
    {
        printf("i is %d\n", i);
        i--;
    }
    /* Loops execute multiple instructions only
     if they are within brackets. The instruction
    i-- was not so therefore the while loop was infinite. */

    printf("That’s it.\n");
    return 0;
}
