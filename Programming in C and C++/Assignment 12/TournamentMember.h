/*
CH-230-A
a12_p3.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <string>
#include <cstring>
class TournamentMember
{
private:
    char first_name[36];
    char last_name[37];
    char date_of_birth[12];
    double height; //the additional two
    double weight; //properties

public:
    static std::string location; //the static property
    static void change_location(std::string new_location);
    //and the method that changes it
    TournamentMember(char new_first_name[], char new_last_name[],
                     char new_date_of_birth[], double new_height,
                     double new_weight);        //the parametric constructor
    TournamentMember();                         //the empty constructor
    ~TournamentMember();                        //the destructor
    TournamentMember(const TournamentMember &); //the copy constructor
    inline char get_first_name()
    { //inline setters and getters
        return first_name[36];
    }
    inline char get_last_name()
    {
        return last_name[37];
    }
    inline char get_date_of_birth()
    {
        return date_of_birth[12];
    }
    inline double get_height()
    {
        return height;
    }
    inline double get_weight()
    {
        return weight;
    }
    inline void set_first_name(char new_first_name[])
    {
        strcpy(first_name, new_first_name);
    }
    inline void set_last_name(char new_last_name[])
    {
        strcpy(last_name, new_last_name);
    }
    inline void set_date_of_birth(char new_date_of_birth[])
    {
        strcpy(date_of_birth, new_date_of_birth);
    }
    inline void set_height(double new_height)
    {
        height = new_height;
    }
    inline void set_weight(double new_weight)
    {
        weight = new_weight;
    }
    void print_information(); //the print method
};
class Player : public TournamentMember
{
private:
    int number;
    char position[100];
    int goals_scored;
    char dominant_foot[6];

public:
    Player(const Player &);
    Player();
    Player(char new_first_name[], char new_last_name[],
           char new_date_of_birth[], double new_height,
           double new_weight, int new_number,
           char new_position[], char dominant_foot[]);
    ~Player();
    void add_goal();
    void print_player_information();
    inline int get_number()
    { //inline setters and getters
        return number;
    }
    inline char get_position()
    {
        return position[100];
    }
    inline int get_goals_scored()
    {
        return goals_scored;
    }
    inline char get_dominant_foot()
    {
        return dominant_foot[6];
    }
    inline void set_number(int new_number)
    {
        number = new_number;
    }
    inline void set_position(char new_position[])
    {
        strcpy(position, new_position);
    }
    inline void set_dominant_foot(char new_dominant_foot[])
    {
        strcpy(dominant_foot, new_dominant_foot);
    }
};