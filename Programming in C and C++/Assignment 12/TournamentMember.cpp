/*
CH-230-A
a12_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <string>
#include "TournamentMember.h"
#include <cstring>
#include <iostream>

void TournamentMember::change_location(std::string new_location)
{ //the method that changes the static location
    TournamentMember::location = new_location;
}
TournamentMember::TournamentMember()
{ //defining the constructors
    std::cout << "Hello from the empty constructor!\n";
}
TournamentMember::TournamentMember(char new_first_name[], char new_last_name[],
                                   char new_date_of_birth[], double new_height,
                                   double new_weight)
{
    strcpy(first_name, new_first_name);
    strcpy(last_name, new_last_name);
    strcpy(date_of_birth, new_date_of_birth);
    height = new_height;
    weight = new_weight;
    std::cout << "Hello from the parametric constructor!\n";
}
TournamentMember::TournamentMember(const TournamentMember
                                       &new_TournamentMemeber)
{
    strcpy(first_name, new_TournamentMemeber.first_name);
    strcpy(last_name, new_TournamentMemeber.last_name);
    strcpy(date_of_birth, new_TournamentMemeber.date_of_birth);
    height = new_TournamentMemeber.height;
    weight = new_TournamentMemeber.weight;
    std::cout << "Hello from the copy constructor!\n";
}
TournamentMember::~TournamentMember()
{
    std::cout << "Hello from the destructor!\n";
}
void TournamentMember::print_information()
{ //the print method
    std::cout << "The tournament from " << location
              << " has the member with the name " << first_name << " "
              << last_name << " born in " << date_of_birth
              << ".\nThey also weigh " << weight << " kg and they are"
              << height << " m tall.\n";
}

void Player::print_player_information()
{
    std::cout << "This player has the number " << number
              << " and plays the position " << position
              << ". They also scored " << goals_scored << " goals at " << location
              << " and they are " << dominant_foot << "-footed.\n";
}
Player::Player(const Player &new_player)
{
    number = new_player.number;
    strcpy(position, new_player.position);
    strcpy(dominant_foot, new_player.dominant_foot);
    goals_scored = new_player.goals_scored;
    std::cout << "Hello from the copy constructor!\n";
}
Player::Player()
{
    goals_scored = 0;
    std::cout << "Hello from the empty constructor!\n";
}
Player::Player(char new_first_name[], char new_last_name[],
               char new_date_of_birth[], double new_height,
               double new_weight, int new_number,
               char new_position[], char new_dominant_foot[]) : TournamentMember(new_first_name, new_last_name,
                                                                                 new_date_of_birth, new_height,
                                                                                 new_weight)
{
    strcpy(position, new_position);
    number = new_number;
    goals_scored = 0;
    strcpy(dominant_foot, new_dominant_foot);
    std::cout << "Hello from the parametric constructor!\n";
}
Player::~Player()
{
    std::cout << "Hello from the destructor!\n";
}
void Player::add_goal()
{
    goals_scored++;
}
void print_player_information();
