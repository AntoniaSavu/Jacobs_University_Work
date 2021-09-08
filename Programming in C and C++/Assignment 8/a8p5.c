/*CH-230-A
a8_p5.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s, t;
    FILE *fp;                     //pointer for the file we read from
    FILE *op;                     //pointer for the file we output from
    fp = fopen("chars.txt", "r"); //opening file
    if (fp == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }

    op = fopen("codesum.txt", "w"); //opening file
    if (op == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    s = getc(fp); //reading the two characters
    t = getc(fp);
    int a = s + t;
    fprintf(op, "%d", a); //outputting in file
    fclose(fp);           //closing the files
    fclose(op);
    return 0;
}