/* 
    Ch-230-A
    a11_p6. [ C++ ]
    Mackenzie Trost
    mtrost@jacobs-university.de
*/ 

#ifndef Vector_h
#define Vector_h

class Vector{
    private:
        int size;
        double *pointer;
    public:
        Vector();           //default
        Vector(int size, double*);    //coponents
        Vector(const Vector&);  //copy
        ~Vector();              //destructor

        void print();
        void setSize(int newSize);
        void setPointer(double* newPointer);
        int getSize();
        double* getPointer();

        double norm();
        Vector add(const Vector) const;
        Vector diff(const Vector) const;
        double s_product(const Vector) const;
};

#endif