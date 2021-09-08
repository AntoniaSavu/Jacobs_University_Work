/*CH-230-A
a8_p8.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char sep[] = " ,?!.\t\n\r";
int main()
{
    int i, n = 0, count = 0;
    char *p, c, s[500];
    FILE *fp;                     //pointer for the 1st file we read from
    fp = fopen("text1.txt", "r"); //opening 1st file
    if (fp == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }

    for (c = getc(fp); c != EOF; c = getc(fp))
        s[n++] = c;

    for (p = strtok(s, sep); p; p = strtok(NULL, sep))
        count++;
    printf(" The file has %d words", count - 1);
    fclose(fp); //closing the files

    return 0;
}