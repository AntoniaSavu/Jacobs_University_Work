/*
CH-231-A
a2_p6.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
std::ifstream f("data.txt");
int main()
{

    std::map<std::string, std::string> mymap;
    //map with the key as a string(the name)
    //and also  a string as the mapped element
    std::string name, birthday;
    while (std::getline(f, name))
    { //reading until the end of the file
        std::getline(f, birthday);
        mymap[name] = birthday;
        //building the map
    }

    std::cout << "Which person would you like to look for?";
    std::getline(std::cin, name);
    auto iterator = mymap.find(name); //searching through the map using find
    if (iterator == mymap.end())
        std::cout << "Name not found!";
    //if the iterator gets to the end of the string without a match
    // it means the name doesn't exist in the map
    else
        std::cout << "Their birthday is: " << iterator->second;
    //otherwise, print the birthday with that name as a key
    return 0;
}
/* for (auto iterator = mymap.begin(); iterator != mymap.end(); iterator++)
        std::cout << iterator->first << ' ' << iterator->second << '\n';
    std::cout << mymap.size();*/
//printing the map, just for reference