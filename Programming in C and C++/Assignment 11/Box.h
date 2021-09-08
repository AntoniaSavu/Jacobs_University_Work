/*
CH-230-A
a11_p1.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <string> // defines standard C++ string class

/* First C++ class */
class Box
{
private:           // data members are private
    double height; //the needed properties
    double width;
    double depth;

public:                               // business logic methods are public
    void setHeight(double newheight); //the setters
    void setWidth(double newwidth);
    void setDepth(double newdepth);
    double getHeight(); //the getters
    double getWidth();
    double getDepth();
    double getVolume();
    Box();                       //the first constructor, no parameters
    Box(double, double, double); //second constructor,all the parameters
    Box(const Box &);            //the copy constructor
    ~Box();                      //the destructor
};