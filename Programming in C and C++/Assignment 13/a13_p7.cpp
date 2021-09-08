/*
CH-230-A
a13_p7.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <exception>

class OwnException : std::exception
{ ///ownexception class, derived from exception
public:
    OwnException(const char[23]){};
    //constructor which takes a string as the parameter
    const char *what() const noexcept
    { //overwriting what() (will never throw)
        return "OwnException\n";
    }
};

void exception_thrower(int integer)
{ //function that throws the right exceptions given the case
    if (integer == 1)
        throw 'a';
    else

        if (integer == 2)

        throw 12;

    else

        if (integer == 3)
        throw true;
    else

        throw OwnException("Default case exception");
    //calling constructor
}

int main()
{
    //implementing all the four cases
    try
    {
        exception_thrower(1);
    }
    catch (const char e)
    {
        std::cerr << "Caught in main: " << e << '\n';
    }
    try
    {
        exception_thrower(2);
    }
    catch (const int e)
    {
        std::cerr << "Caught in main: " << e << '\n';
    }
    try
    {
        exception_thrower(3);
    }
    catch (const bool e)
    {
        std::cerr << "Caught in main: " << e << '\n';
    }
    try
    {
        exception_thrower(5);
    }
    catch (const OwnException &e)
    { //OwnException type
        std::cerr << "Caught in main: " << e.what() << '\n';
    }

    return 0;
}