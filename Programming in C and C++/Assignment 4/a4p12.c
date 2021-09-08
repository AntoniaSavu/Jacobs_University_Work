/*CH-230-A
a4_p12.[c or cpp or h]
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replaceAll(char *str, char c, char e)
{ //function that replaces all c elements with e
    int i, n = strlen(str);
    for (i = 0; i < n; i++)
        if (str[i] == c)
            str[i] = e;
}
int main()
{
    char line[100], c, e;
    while (1)
    {

        scanf("%s", line);
        getchar();

        if (strcmp(line, "stop") != 0) //break condition
        {
            scanf("%c", &c);
            getchar();
            scanf("%c", &e);
            getchar();
            replaceAll(line, c, e); //calling the function
            printf("%s", line);     //printing the changed string
        }
        else

            break;
    }
    return 0;
}