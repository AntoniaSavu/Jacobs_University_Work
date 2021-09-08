/*CH-230-A
a7_p4.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <ctype.h>

char s[101];
void allupper(char s[])
{ //function that prints
    //all the characters of the string uppercase
    int i;
    for (i = 0; s[i]; i++)
        printf("%c", toupper(s[i]));
}
void alllower(char s[])
{ //function that prints
    //all the characters of the string lowercase
    int i;
    for (i = 0; s[i]; i++)
        printf("%c", tolower(s[i]));
}

void different(char s[])
{ //function that prints
    //all the characters of the string swapped
    //(if uppercase , prints lowercase and vice versa)
    int i;
    for (i = 0; s[i]; i++)
        if (islower(s[i]))
            printf("%c", toupper(s[i]));
        else
        {
            printf("%c", tolower(s[i]));
        }
}

int main()
{
    char t;
    fgets(s, 101, stdin);
    while (1) //infinite loop
    {

        scanf("%c", &t);
        getchar();
        int a = (int)t - 48;
        if (a == 4)
            break; //breaking the infinite loop
        void (*p[])(char s[]) = {allupper, alllower, different};
        //the function pointer array
        (*p[a - 1])(s); //calling the function we need based on the
        //char entered
    }

    return 0;
}