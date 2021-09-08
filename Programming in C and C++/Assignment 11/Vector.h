/*
CH-230-A
Vector.h A11_p6
Muhamad KADI AMEEN
m.kadiameen@jacobs-university.de
*/

class Vector
{
private:
    //size and pointer as properties
    double *P;
    int size;

public:
    Vector();
    Vector(int n_size);
    Vector(const Vector &);
    ~Vector();

    double at(int index) const; //return the value at given index
    void setAt(int index, double value);

    int length() const;
    void grow(int s); //extend the size of the Vector to a given number

    void print() const;
    double norm() const;
    Vector sum(const Vector &other) const;
    Vector diff(const Vector &other) const;
    double scalarP(const Vector &other) const;
};