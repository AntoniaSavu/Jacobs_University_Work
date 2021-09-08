/*
CH-230-A
a2_p9.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
int main()
{
        char x;
        scanf("%c", &x);

        /* in order to find the type of the character, I used
ASCII code. Letters are between 65 and 90 or between 97 and 122.
Digits are between 48 and 97. If the character does not have the ASCII
code within these limits, then it must be some other symbol*/

        if (((int)x >= 65 && (int)x <= 90) || ((int)x >= 97 && (int)x <= 122))
                printf("%c is a letter\n", x);

        else if ((int)x >= 48 && (int)x <= 57)
                printf("%c is a digit\n", x);
        else
                printf("%c is some other symbol\n", x);

        return 0;
}