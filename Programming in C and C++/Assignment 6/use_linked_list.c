#include <stdlib.h>
#include "linked_list.h"
int main()
{
    struct list *mylist = NULL;
    int i = 1, x;
    char ch;
    while (i)
    { //infinite loop
        scanf("%c", &ch);
        switch (ch) //switch instruction
        {
        case 'b':
            scanf("%d", &x);
            mylist = push_front(mylist, x); //calling the required
            //functions for each case
            break;

        case 'a':
            scanf("%d", &x);
            mylist = push_back(mylist, x);
            break;
        case 'r':
            mylist = rem(mylist);
            break;
        case 'p':
            print_list(mylist);
            break;
        case 'q':
            dispose_list(mylist);
            i = 0;
            break;
        default:
            break;
        }
    }

    return 0;
}