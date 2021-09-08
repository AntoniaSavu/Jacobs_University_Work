/*
CH-230-A
a11_p4.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>

using namespace std;

class Creature
{
public:
    Creature();
    void run() const;
    ~Creature();

protected:
    int distance;
};
class Wizard : public Creature
{
public:
    Wizard();
    void hover() const;

private:
    int distFactor;
};

class Fairy : public Creature
{ //created the fairy class
public:
    Fairy();
    void fly() const;
    //with the method fly
private:
    int flying;
    //and a flying property
};

class Dragon : public Creature
{ //created the dragon class
public:
    Dragon();
    void bfire() const;
    //with the breathing fire method

private:
    int fire;
    //and a fire property
};
