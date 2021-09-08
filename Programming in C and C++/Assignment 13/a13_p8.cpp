/*
CH-230-A
a13_p8.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>

class Motor
{
public:
    Motor()
    {
        throw("This motor has problems");
        //thrown for the motor class
    }
};

class Car
{
protected:
    Motor m_motor;

public:
    Car()
    {
        Motor();
    }
};
class Garage
{
protected:
    Car c_car;

public:
    Garage()
    {
        Car();
        throw("The car in this garage has problems with the motor");
        //throwing this from the body of the garage constructor
    }
};

int main()
{
    try
    {
        Garage g;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    /* or:

catch (const std::char  *e)
    {
        std::cerr << e << '\n';
    }*/
    //I am not sure whih one is wanted.
    return 0;
}