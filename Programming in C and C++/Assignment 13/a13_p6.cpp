/*
CH-230-A
a13_p6.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <vector>
#include <stdexcept> // has std::out_of_range
int main()
{

    std::vector<int> my_vector(20);
    //creating a vector
    for (int i = 0; i < 20; i++)
    { //making it have 20 8s
        my_vector.at(i) = 8;
    }
    try
    { //the try wehere we attempt to access element 21
        my_vector.at(21);
    }
    catch (const std::out_of_range &e)
    { //out of range error
        std::cerr << e.what() << '\n';
    }

    return 0;
}