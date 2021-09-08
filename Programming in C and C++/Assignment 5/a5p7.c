/*CH-230-A
a5_p7.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char s[101], t[101], *u;

    fgets(s, sizeof(s), stdin); //reading the two strings
    fgets(t, sizeof(t), stdin);
    s[strlen(s) - 1] = 0; //getting rid of the \n fgets adds
    t[strlen(t) - 1] = 0;
    int n = strlen(s) + strlen(t);

    u = (char *)malloc(sizeof(char) * n); //dynamically allocating array
    if (u == NULL)
        exit(1);
    strcpy(u, s);
    //copying the first string into the third
    strcat(u, t);
    //concatenating the second string

    printf("Result of concatenation: %s\n", u);
    free(u); //freeing the allocated memory
    return 0;
}