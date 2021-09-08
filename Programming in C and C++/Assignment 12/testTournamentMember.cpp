/*
CH-230-A
a12_p2.cp
Antonia Savu
asavu@jacobs-university.de
*/
#include <string>
#include "TournamentMember.h"
#include <cstring>
#include <iostream>
std::string TournamentMember::location = "Paris";
int main()
{
    char first_name[36], last_name[37], date_of_birth[12];
    double height, weight;
    TournamentMember member_one;
    //initializing the first object usigng the empty constructor

    std::cin >> first_name; //reading from the keyboard all the properties
    std::cin.get();
    std::cin >> last_name;
    std::cin.get();
    std::cin >> date_of_birth;
    std::cin.get();
    std::cin >> height >> weight;
    std::cin.get();
    member_one.set_first_name(first_name); //setting all these properties
    member_one.set_last_name(last_name);   //using setters
    member_one.set_date_of_birth(date_of_birth);
    member_one.set_height(height);
    member_one.set_weight(weight);
    member_one.print_information(); //printing the information

    std::cin >> first_name;
    std::cin.get();
    std::cin >> last_name;
    std::cin.get();
    std::cin >> date_of_birth;
    std::cin.get();
    std::cin >> height >> weight;
    std::cin.get();
    TournamentMember member_two(first_name, last_name,
                                date_of_birth, height, weight);
    //initializing the second object using the parametric constructor
    member_two.print_information(); //printing the information

    TournamentMember member_three(member_two);
    //initializing the third object using the copy constructor
    member_three.print_information(); //printing the information
    TournamentMember::change_location("Berlin");
    //calling the change method and then printing
    // all the objects again to illustrate the change
    std::cout << "\n\n\nAfter changing the location:\n";
    member_one.print_information();
    member_two.print_information();
    member_three.print_information();
}