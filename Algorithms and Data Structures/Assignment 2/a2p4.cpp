/*
CH-231-A
a2_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{

    std::vector<int> myvector;
    for (int i = 0; i < 30; i++)
        myvector.push_back(i + 1);
    //pushing the first 30 values from 1
    myvector.push_back(5);                     //adding 5 at the end
    reverse(myvector.begin(), myvector.end()); //reversing the vector
    for (auto it = myvector.begin(); it != myvector.end(); it++)
        std::cout << *it << ' ';
    //printing the vector
    std::replace(myvector.begin(), myvector.end(), 5, 129);
    //replacing all occurrences of 5 with 129
    std::cout << '\n';
    for (auto it = myvector.begin(); it != myvector.end(); it++)
        std::cout << *it << ' ';
    //and then printing again

    return 0;
}