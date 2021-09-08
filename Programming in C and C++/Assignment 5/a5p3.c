/*CH-230-A
a5_p3.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int count_lower(char *str)
{
    int c = 0;
    char *i;
    for (i = str; *i != 0; i++)
        if (tolower(*i) == *i)
            c++;
    return c;
    ///function to count the lower characters
}
int main()
{
    char s[51];
    while (1)
    {
        fgets(s, 51, stdin); //reading string
        if (s[0] == '\n')    //empty string condition
            break;
        else
        {
            s[strlen(s) - 1] = 0; //getting rid of the extra \n
            //from fgets
            printf("Number of lowercase characters:%d\n", count_lower(s));
        }
    }

    return 0;
}