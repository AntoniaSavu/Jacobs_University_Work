/*
CH-230-A
a10_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include "City.h"

using namespace std;

void city_data(City Bremen)
{
    string name;
    int x;
    double y;

    cout << "Please enter the following:\n";
    cout << "Name:";
    getline(cin, name);
    Bremen.setName(name);
    cout << "Mayor:";
    getline(cin, name);
    Bremen.setMayor(name);
    cout << "Number of inhabitants:";
    cin >> x;
    Bremen.setInhabitants(x);
    cout << "Area:";
    cin >> y;
    Bremen.setArea(y);
    cout << "\n\n";
    Bremen.print();
    //function that gets input from the keyboard
    //for all the characteristics of an object
    //then prints them
}
int main()
{
    City Bremen, Paris, London;
    city_data(Bremen); //calling the function
    cin.get();
    cout << "\n\n";
    city_data(Paris); //for each of the cities
    cin.get();
    cout << "\n\n";
    city_data(London);

    return 0;
}