/*CH-230-A
a8_p9.c
Antonia Savu
asavu@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[500], t[1500], buffer[64];
    FILE *fp; //pointer to the file we read from
    FILE *op; //pointer to the file we output
    //and later read aswell

    op = fopen("output.txt", "wb");
    //opening file where we will write the input
    if (op == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    int n;
    scanf("%d", &n); //reading the number of files
    getchar();       //'\n' so fgets reads the correct line
    for (int i = 0; i < n; i++)
    {                         //loop to read all the files we need
        fgets(s, 500, stdin); //reading the file nane
        s[strlen(s) - 1] = 0; //getting rid of the extra \n from fgets
        fp = fopen(s, "rb");  //opening file
        if (fp == NULL)
        {
            printf(" Cannot open file !\n");
            exit(1);
        }
        size_t p = fread(buffer, sizeof(char), 64, fp); //buffer
        fwrite(buffer, 1, p, op);
        //writing in the output file
        const char endline = '\n';
        fwrite(&endline, 1, 1, op);
        fclose(fp);
    }
    fclose(op);                     //closing the output file
    op = fopen("output.txt", "rb"); //so i can reopen it as a reading file
    if (op == NULL)
    {
        printf(" Cannot open file !\n");
        exit(1);
    }
    printf("Concatenating the content of %d files ...\n", n);
    printf("The result is:\n");
    fread(t, 1, 100, op);
    //storing everything from the outpute file into a string t
    printf("%s", t); //printing the string
    printf("The result was written into output.txt");
    fclose(op); //closing the file
    return 0;
}
/* references i used:
https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
*/