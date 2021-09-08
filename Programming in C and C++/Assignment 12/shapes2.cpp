#include <cmath>
#include <iostream>
#include "shapes2.h"

using namespace std;

Shape::Shape(const string &n) : name(n)
{
}

void Shape::printName() const
{
    cout << name << endl;
}

CenteredShape::CenteredShape(const string &n, double nx, double ny) : Shape(n)
{
    x = nx;
    y = ny;
}

RegularPolygon::RegularPolygon(const string &n, double nx, double ny, int nl)
    : CenteredShape(n, nx, ny)
{
    EdgesNumber = nl;
}

Circle::Circle(const string &n, double nx, double ny, double r)
    : CenteredShape(n, nx, ny)
{
    Radius = r;
}
Hexagon::Hexagon(const std::string &nname, double nx, double ny,
                 int e, double s, const std::string c) : RegularPolygon(nname, nx, ny, 6)
{
    side = s;
    color = c;
    cout << "Calling the constructor with parameters\n";
}
Hexagon::Hexagon(const Hexagon &z) : RegularPolygon(z)
{
    side = z.side;
    color = z.color;
    cout << "Calling the copy constructor\n";
}
Hexagon::~Hexagon()
{
    cout << "Calling the destructor\n";
}
double Hexagon::perimeter()
{
    return side * 6;
}
double Hexagon::area()
{
    double aux = sqrt(3) * 3 / 2;
    return aux * side * side;
}
void Hexagon::setSide(double newside)
{
    side = newside;
}
double Hexagon::getSide()
{
    return side;
}
void Hexagon::setColor(std::string ncolor)
{
    color = ncolor;
}
std::string Hexagon::getColor()
{
    return color;
}