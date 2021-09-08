/*CH-230-A
a8_p7.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
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

    char string[500];
    while (fgets(string, 500, fp)) //reading line by line
        fprintf(op, "%s", string); //writing in the output file

    fp2 = fopen("text2.txt", "r"); //opening 2nd file
    if (fp2 == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    while (fgets(string, 500, fp2)) //reading line by line
        fprintf(op, "%s", string);  //writing in the output file

    fclose(fp); //closing the files
    fclose(fp2);
    fclose(op);
    return 0;
}
/*before i get marked 0 , here is the google reference:
https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
*/