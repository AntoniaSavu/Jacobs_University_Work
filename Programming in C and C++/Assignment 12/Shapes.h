/*
CH-230-A
a12_p1.h
Antonia Savu
asavu@jacobs-university.de
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

class Shape
{                     // base class
private:              // private access modifier: could also be protected
    std::string name; // every shape will have a name
public:
    Shape(const std::string &); // builds a shape with a name
    Shape();                    // empty shape
    void printName() const;     // prints the name
};

class CenteredShape : public Shape
{ // inherits from Shape
private:
    double x, y; // the center of the shape
public:
    CenteredShape(const std::string &, double, double);
    CenteredShape();
    void move(double, double); // moves the shape, i.e. it modifies it center
};

class RegularPolygon : public CenteredShape
{ // a regular polygon is a centered_shape with a number of edges
private:
    int EdgesNumber;

public:
    RegularPolygon(const std::string &, double, double, int);
    RegularPolygon();
};
class Hexagon : public RegularPolygon
{
private:
    double side; //the properties
    std::string color;

public:
    ~Hexagon(); //destructor
    Hexagon(const std::string &, double, double,
            int, double, const std::string);
    //constructor with parameters
    Hexagon(const Hexagon &);     //copy consructor
    double perimeter();           //methods for perimeter
    double area();                //and area
    void setSide(double newside); //setters and getters
    double getSide();
    void setColor(std::string ncolor);
    std::string getColor();
};

class Circle : public CenteredShape
{ // a Circle is a shape with a center and a radius
private:
    double Radius;

public:
    Circle(const std::string &, double, double, double);
    Circle();
    Circle(const Circle &);
};

#endif