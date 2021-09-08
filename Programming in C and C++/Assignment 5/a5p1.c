/*CH-230-A
a5_p1.c
Antonia Savu
asavu@jacobs-university.de
*/
#include <stdio.h>
void triangle_shape(int n, char c)
{
    int i, aux;
    for (i = n; i > 0; i--)
    {            //loop from n to 1 in order to output
        aux = i; //taking an auxilliary variable in order to
        //help give it that triangle shape
        while (aux)
        {
            printf("%c", c);
            aux--;
        }
        printf("\n");
    }
}
int main()
{
    int n;
    char ch;
    scanf("%d %c", &n, &ch); //reading the input
    triangle_shape(n, ch);   //calling the function

    return 0;
}