/*
CH-230-A
a4_p2.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
int main()
{
    char string[51];
    int n, i;
    fgets(string, sizeof(string), stdin); // reading the string
    n = strlen(string);
    string[n - 1] = '\0';
    //terminating the string early
    // due to fstring adding \n
    // at the end

    for (i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
            printf("%c\n", string[i]);
        else
        {
            printf(" %c\n", string[i]);
            //adding extra spaces before elements
            //in odd positions to give it that zig zag
            //shape
        }
    }

    return 0;
}