/*
CH-230-A
a12_p3.cp
Antonia Savu
asavu@jacobs-university.de
*/
#include <string>
#include "TournamentMember.h"
#include <cstring>
#include <iostream>
std::string TournamentMember::location = "Paris";
char first_name[36], last_name[37], date_of_birth[12],
    position[100], dominant_foot[6];
double height, weight, number;
void reading()
{
    //made this a function so i don't have to write twice
    std::cin.getline(first_name, 36);
    std::cin.get();
    std::cin.getline(last_name, 37);
    std::cin.get();
    std::cin.getline(date_of_birth, 12);
    std::cin.get();
    std::cin >> height >> weight >> number;
    std::cin.get();
    std::cin.getline(position, 100);
    /*this does not work if everything is written on one line. 
    therefore the input must be something like:
    attacking midfield(position)
    right(dominant foot)

    in order for it to work on one line aswell , 
    we can write cin>>position. 
    but that means that we can't allow for 
    positions with spaces in their name*/
    std::cin >> dominant_foot;
    std::cin.get();
}
int main()
{

    Player player_one;
    //initializing the first object usigng the empty constructor
    reading();
    //calling the function with all the parameters
    player_one.set_first_name(first_name); //setting all these properties
    player_one.set_last_name(last_name);   //using setters
    player_one.set_date_of_birth(date_of_birth);
    player_one.set_height(height);
    player_one.set_weight(weight);
    player_one.set_number(number);
    player_one.set_dominant_foot(dominant_foot);
    player_one.set_position(position);
    player_one.print_player_information(); //printing the information
    reading();
    //calling the function with all the parameters
    Player player_two(first_name, last_name,
                      date_of_birth, height,
                      weight, number, position, dominant_foot);
    //initializing the second object using the parametric constructor
    player_two.print_player_information(); //printing the information
    player_two.add_goal();                 //adding a goal
    player_two.print_player_information();
    //and printing afterwards again to see that it works
    Player player_three(player_two);
    //initializing the third object using the copy constructor
    player_three.print_player_information(); //printing the information
    TournamentMember::change_location("Hamburg");
    //calling the change method and then printing
    // all the objects again to illustrate the change
    std::cout << "\n\n\nAfter changing the location:\n";
    player_one.print_player_information();
    player_two.print_player_information();
    player_three.print_player_information();
}