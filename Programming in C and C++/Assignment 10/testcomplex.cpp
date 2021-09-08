/*
CH-230-A
a13_p2.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <cstdlib>
#include "Complex.h"
#include <fstream>
std::ifstream f("in1.txt");    //the two
std::ifstream f1("in2.txt");   //input files
std::ofstream g("output.txt"); //the output file

int main(int argc, char **argv)
{
  Complex number_1, number_2, sum, difference, product;
  f >> number_1;                    //reading the two
  f1 >> number_2;                   //complex numbers
  sum = number_2 + number_1;        //computing the sum
  difference = number_1 - number_2; //difference
  product = number_1 * number_2;    //and product
  g << "Sum: \n"                    //printing in output file
    << sum << "Difference: \n"
    << difference << "Product: \n"
    << product;
  std::cout << "Sum: \n" //printing in terminal
            << sum << "Difference: \n"
            << difference << "Product: \n"
            << product;
  return 0;
}
