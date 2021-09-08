/*CH-230-A
a4_p4.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>

int count_consonants(char str[])
{
    int i, n, c = 0;
    n = strlen(str);
    for (i = 0; i < n; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z'))
            //checking if the element is a letter
            if (strchr("aeiouAEIOU", str[i]) == NULL)
                //checking if its a consonant
                c++;
    }

    return c;
}

int main()
{
    char line[100];
    while (1)
    {
        fgets(line, 100, stdin);
        if (line[0] != '\n') //condition to break the endless loop
            printf("Number of consonants=%d\n", count_consonants(line));
        else

            break;
    }
    return 0;
}