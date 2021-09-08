/*
CH-231-A
a2_p5.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <list>
#include <stdlib.h>
#include <time.h>
int main()
{
    std::list<int> Lotto;
    // I chose list because of the method 'unique'
    //as it makes my life easier when it comes to
    //not having duplicates

    srand(static_cast<unsigned int>(time(0)));
    srand(time(NULL));
    int random;
    while (Lotto.size() < 6)
    {
        //keeps picking random numbers
        //until there is a total of 6
        random = rand() % 49 + 1;
        Lotto.push_back(random);
        Lotto.sort();
        //sorting them in order for
        //the unique method to work properly
        Lotto.unique();
        //making sure there are no duplicates
    }

    for (auto it = Lotto.begin(); it != Lotto.end(); it++)
        std::cout << *it << ' ';
    //printing the list ( which is already ordered)
    return 0;
}