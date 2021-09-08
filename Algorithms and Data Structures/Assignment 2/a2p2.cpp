/*
CH-231-A
a2_p2.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <deque>
int main()
{
    std::deque<float> A;
    float x;
    std::cin >> x;
    while (x)
    {

        if (x > 0)
            A.push_back(x);
        //inserting the positive elements at the end
        else
            A.push_front(x);
        //inserting the negative elements at the beginning
        std::cin >> x;
    }
    for (auto iterator = A.begin(); iterator != A.end(); iterator++)
        std::cout << *iterator << ' ';
    //simple print

    std::cout << '\n';
    for (auto iterator = A.begin(); iterator != A.end(); iterator++)
    {
        if (*iterator > 0)
        { //the zero should be placed at the encounter with the first positive number
            A.insert(iterator, 0);
            break;
        }
    }

    for (auto iterator = A.begin(); iterator != A.end(); iterator++)
    { //printing again, with semicolons
        if (iterator != --A.end())
            std::cout << *iterator << ';';
        else
            std::cout << *iterator;
    }
    return 0;
}