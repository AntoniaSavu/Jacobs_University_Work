/*CH-230-A
a8_p7.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    FILE *fp;                       //pointer for the 1st file we read from
    FILE *fp2;                      //pointer for the 2nd file we read from
    FILE *op;                       //pointer for the file we output from
    fp = fopen("text1.txt", "r");   //opening 1st file
    op = fopen("merge12.txt", "w"); //opening output file
    if (fp == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
    { //iterating character by character and printing it to
        //the output file
        fprintf(op, "%c", c);
    }

    fp2 = fopen("text2.txt", "r"); //opening 2nd file
    if (fp2 == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    for (c = getc(fp2); c != EOF; c = getc(fp2))
    { //iterating character by character and printing it to
        //the output file
        fprintf(op, "%c", c);
    }

    fclose(fp); //closing the files
    fclose(fp2);
    fclose(op);
    return 0;
}