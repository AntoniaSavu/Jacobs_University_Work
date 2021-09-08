#include <string> // defines standard C++ string class
#include <cstdlib>
#include <iostream>
using namespace std;
/* First C++ class */
class Critter
{
private: // data members are private
    int hunger;
    int boredom;
    double height;

public: // business logic methods are public
    // setter methods
    void setName(std::string &newname);
    void setHunger(int newhunger);
    void setBoredom(int newboredom);
    // getter method
    int getHunger();
    // service method
    void print();
};

void Critter::setName(string &newname)
{
    name = newname;
}

void Critter::setHunger(int newhunger)
{
    hunger = newhunger;
}

void Critter::print()
{
    cout << "I am " << name << ". My hunger level is " << hunger << "." << endl;
}

int Critter::getHunger()
{
    return hunger;
}
int main(int argc, char **argv)
{
    Critter c;

    string name;
    int hunger;

    cout << endl
         << "Please enter data: " << endl;
    cout << "Name: ";
    // cin >> name; will not work if name contains
    // spaces
    getline(cin, name);
    //c.setName(name);
    //c.setName(name);
    cout << "Hunger: ";
    cin >> hunger;
    c.setHunger(hunger);

    cout << "You have created:" << endl;
    c.print();
    return 0;
}
