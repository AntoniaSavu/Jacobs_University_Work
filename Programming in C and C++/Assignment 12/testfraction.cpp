/*
CH-230-A
a12_p5.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include "fraction.h"

using namespace std;

int main(void)
{
    Fraction fraction_one, fraction_two, fraction_sum, fraction_diff;
    //initialising the fractions
    cin >> fraction_one >> fraction_two;
    //reading them
    fraction_sum = fraction_one + fraction_two;
    //storing the sum in a different fraction
    fraction_diff = fraction_one - fraction_two;
    //storing the difference in a different fraction
    cout << "The greater fraction is: ";
    if (fraction_one > fraction_two)
        //printing the greater fraction
        cout << fraction_one;
    else

        cout << fraction_two;

    cout << "Sum: " << fraction_sum
         << "Substraction: " << fraction_diff;
    //and printing the Product and quotient
}
