/*
CH-231-A
a2_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <list>
std::ofstream g("listB.txt");
int main()
{
    std::list<int> A, B;
    int x;
    std::cin >> x;
    while (x > 0)
    {
        A.push_back(x);  //adding the elements at the end of list A
        B.push_front(x); //adding the elements at the beginning of list A
        std::cin >> x;
    }
    for (auto iterator = A.begin(); iterator != A.end(); iterator++)
    { //printing list A on standard output
        std::cout << *iterator << ' ';
    }
    for (auto iterator = B.begin(); iterator != B.end(); iterator++)
    { //printing list B in the file
        g << *iterator << ' ';
    }
    std::cout << '\n';
    int aux = A.front();
    A.push_back(aux); //adding the first element at the end of the list
    A.pop_front();    //then removing it from the front
    aux = B.front();  //same for B
    B.push_back(aux);
    B.pop_front();
    for (auto iterator = A.begin(); iterator != A.end(); iterator++)
    { //printing A and B again using commas
        if (iterator != --A.end())
            std::cout << *iterator << ',';
        else
            std::cout << *iterator;
    }
    std::cout << '\t';
    for (auto iterator = B.begin(); iterator != B.end(); iterator++)
    {
        if (iterator != --B.end())
            std::cout << *iterator << ',';
        else
            std::cout << *iterator;
    }
    std::cout << '\n';
    A.merge(B); //merging and sorting the two lists
    A.sort();
    for (auto iterator = A.begin(); iterator != A.end(); iterator++)
    { //and finally printing the result
        std::cout << *iterator << ' ';
    }

    return 0;
}