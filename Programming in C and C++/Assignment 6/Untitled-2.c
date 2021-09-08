#include <stdio.h>

int main()
{
    unsigned char ch, a;
    scanf("%c", &ch);
    int UC_Size = 0;
    printf("The decimal representation is: %d\n", ch);
    a = ch;

    while (a)
    {
        UC_Size++;
        a >>= 1;
    }
    printf("The backwards binary representation is: ");
    for (int i = 0; i < UC_Size; i++)
        printf("%d", ((ch >> i) & 1));

    printf("\n");

    return 0;
}