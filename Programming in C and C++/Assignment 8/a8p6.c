/*CH-230-A
a8_p6.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a, b;
    FILE *fp;                       //pointer for the 1st file we read from
    FILE *fp2;                      //pointer for the 2nd file we read from
    FILE *op;                       //pointer for the file we output from
    fp = fopen("fileone.txt", "r"); //opening 1st file
    if (fp == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    fscanf(fp, "%lf", &a); //reading the first double

    fp2 = fopen("filetwo.txt", "r"); //opening 2nd file
    if (fp2 == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    fscanf(fp2, "%lf", &b); //reading the second variables

    double sum, dif, prod, division;
    //computing the sum, difference, product and division of the two doubles
    sum = a + b;
    dif = a - b;
    prod = a * b;
    division = a / b;

    op = fopen("results.txt", "w"); //opening file
    fprintf(op, "Sum: %lf\n Difference: %lf\n Product: %lf\n Division: %lf\n", sum, dif, prod, division);
    //outputting in file the computed variables
    fclose(fp); //closing the files
    fclose(fp2);
    fclose(op);
    return 0;
}