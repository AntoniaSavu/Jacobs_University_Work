/*CH-230-A
a8_p8.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sep[] = " ,?!.\t\n\r";
//string with the characters that separate words
int main()
{
    int count = 0;
    char c = '\0', s[500];
    FILE *fp;             //pointer for the file we read from
    fgets(s, 500, stdin); //reading the file name
    s[strlen(s) - 1] = 0;
    fp = fopen(s, "r"); //opening the reading  file
    if (fp == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    char prev = getc(fp);
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (strchr(sep, c) && !strchr(sep, prev))
            //using strchr in order to detect words
            count++;
        prev = c;
        //counting the words using two variables to
        //check the file
    }
    if (prev != '\0' && strchr(sep, prev) == NULL)
        count++; //edge case when the file does not end with one of the
    //symbols

    printf(" The file contains %d words.", count);
    fclose(fp); //closing the files

    return 0;
}