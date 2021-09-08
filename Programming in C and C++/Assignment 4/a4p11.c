/*CH-230-A
a4_p11.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int count_insensitive(char *str, char c)
{ //function for counting the same element
    int count = 0;
    for (int i = 0; str[i]; i++)

        if (tolower(c) == tolower(str[i]))
            count++;
    return count;
}
int main()
{
    char *dyn_string, *s;

    dyn_string = (char *)malloc(sizeof(char) * 51);
    //dynamically allocating string
    if (dyn_string == NULL)
        exit(1);

    fgets(dyn_string, 51, stdin);

    s = (char *)malloc(sizeof(char) * strlen(dyn_string));
    //dynamically allocating string
    if (s == NULL)
        exit(1);
    strcpy(s, dyn_string); //copying the first string into the second one
    //printing and calling the function for every case stated:
    printf("The character 'b' occurs %d times\n", count_insensitive(s, 'b'));
    printf("The character 'H' occurs %d times\n", count_insensitive(s, 'H'));
    printf("The character '8' occurs %d times\n", count_insensitive(s, '8'));
    printf("The character 'u' occurs %d times\n", count_insensitive(s, 'u'));
    printf("The character '$' occurs %d times", count_insensitive(s, '$'));
    free(dyn_string); //freeing the memory allocated for the two strings
    free(s);

    return 0;
}