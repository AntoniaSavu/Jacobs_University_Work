/*
CH-230-A
a10_p3.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <string>

class City
{
private:
    std::string name;
    int num_inhabitants;
    std::string mayor;
    double area;
    //the properties needed

public:
    void setName(std::string &newname);//setter
    void setInhabitants(int newnum_inhabitants);//for each one
    void setMayor(std::string &newmayor);//of the properties
    void setArea(double newarea);
    std::string getName();//getter
    int getInhabitants();//for each one
    std::string getMayor();//of the properties
    double getArea();
    void print();//printing function
};