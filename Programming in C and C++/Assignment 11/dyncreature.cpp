/*
CH-230-A
a11_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <cstring>
#include "Creature.h" //including the header
using namespace std;

int main()
{
    char s[300];

    while (1)
    { //infinite loop
        cin >> s;
        //reading input
        cin.get();
        if (strcmp(s, "wizard") == 0)
        { //checking for every case
            Wizard *w = new Wizard();
            //dynamically allocating
            w->hover();
            //calling specific method
            delete w;
            //freeng memory
        }
        if (strcmp(s, "object1") == 0)
        {
            Fairy *f = new Fairy();
            f->fly();
            delete f;
        }
        if (strcmp(s, "object2") == 0)
        {
            Dragon *d = new Dragon();
            d->bfire();
            delete d;
        }
        if (strcmp(s, "quit") == 0)
            break; //breaking the loop
    }

    return 0;
}