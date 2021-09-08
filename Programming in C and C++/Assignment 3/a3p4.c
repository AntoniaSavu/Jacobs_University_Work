/*
CH-230-A
a3_p4.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
int position(char str[], char c)
{
    int idx;
    for (idx = 0; str[idx] != '\0'; ++idx)
    {
        if (str[idx] == c)
            break;
    } ///The loop needed brackets in order to work
    return idx;
}
int main()
{
    char line[80];
    while (1)
    {
        printf("Enter string:\n");
        fgets(line, sizeof(line), stdin);
        printf("The first occurrence of g is: %d\n", position(line, 'g'));
    }
    return 0; //was missing return 0;
}