/*
CH-230-A
a12_p5.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include "fraction.h"

Fraction::Fraction()
{
    num = 1;
    den = 1;
}

Fraction::Fraction(int n, int d)
{
    int tmp_gcd = gcd(n, d);

    num = n / tmp_gcd;
    den = d / tmp_gcd;
}

int Fraction::gcd(int a, int b)
{

    int r, temp_a = a, temp_b = b;
    while (temp_b != 0)
    {
        r = temp_a % temp_b;
        temp_a = temp_b;
        temp_b = r;
    }
    return temp_a;
}

int Fraction::lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

void Fraction::print()
{
    std::cout << num << "/" << den << std::endl;
}
std::istream &operator>>(std::istream &in, Fraction &frac)
{ //definition for the >> overload
    char slash;
    in >> frac.num >> slash >> frac.den;
    if (frac.den == 0)
    { //if the denominator is 0, valid is considered invalid
        std::cout << "Invalid input!";
        exit(1);
    }
    else
        return in;
}

std::ostream &operator<<(std::ostream &os, const Fraction &frac)
{ //definition for the << overload
    os << frac.num << '/' << frac.den << '\n';
    return os;
}
Fraction Fraction::operator*(Fraction frac)
{ //overloading the * operator so that it multiplies fractions
    Fraction multiply(this->num * frac.num, this->den * frac.den);
    return multiply;
}

Fraction Fraction::operator/(Fraction frac)
{ //overloading the * operator so that it divides fractions
    Fraction quotient(this->num * frac.den, this->den * frac.num);
    return quotient;
}
Fraction Fraction::operator+(Fraction frac)
{ //overloading the + operator so that it adds fractions
    Fraction addition(this->num * lcm(this->den, frac.den) / this->den +
                          frac.num * lcm(this->den, frac.den) / frac.den,
                      lcm(this->den, frac.den));
    return addition;
}
Fraction Fraction::operator-(Fraction frac)
{ //overloading the - operator so that it subtracts fractions
    Fraction substraction(this->num * lcm(this->den, frac.den) / this->den -
                              frac.num * lcm(this->den, frac.den) / frac.den,
                          lcm(this->den, frac.den));
    return substraction;
}
void Fraction ::operator=(Fraction frac)
{ //overloading the equal operator so that it assigns a fraction to another
    this->num = frac.num;
    this->den = frac.den;
}
bool Fraction::operator<(Fraction frac)
{ //overloading the < so that it compares fractions
    double result1 = this->num / this->den;
    double result2 = frac.num / frac.den;
    return result1 < result2;
}
bool Fraction::operator>(Fraction frac)
{ //overloading the > so that it compares fractions
    double result1 = this->num / this->den;
    double result2 = frac.num / frac.den;
    return result1 > result2;
}