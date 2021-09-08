/*
CH-230-A
a3_p11.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char one[101], two[101], three[101], c;
    char *position;
    int length1, length2;
    fgets(one, sizeof(one), stdin); // reading the first string
    one[strlen(one) - 1] = '\0';
    /*because fgets also adds the \n at the end
     I ended the string before that so
     it will be easier to work with*/

    fgets(two, sizeof(two), stdin); //similar to the first string
    two[strlen(two) - 1] = '\0';

    length1 = strlen(one); //computing and printing
    length2 = strlen(two); // the two lengths
    printf("length1=%d\n", length1);
    printf("length2=%d\n", length2);

    strcpy(three, one);
    strcat(three, two); //concatenating the 2 strings
    printf("concatenation=%s\n", three);

    strcpy(three, two);
    printf("copy=%s\n", three); //printing the copy of the second string

    if (strcmp(one, two) < 0) //comparing the strings
        printf("one is smaller than two\n");
    else
    {
        if (strcmp(one, two) > 0)
            printf("one is larger than two\n");
        else

            printf("one is equal to two\n");
    }

    scanf("%c", &c);            // reading the character
    if (strchr(two, c) != NULL) //searching for it in the second string
    {
        position = strchr(two, c);
        printf("position=%ld\n", position - two);
    }
    else
    {
        printf("The character is not in the string\n");
    }

    return 0;
}