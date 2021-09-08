/*
CH-231-A
a1_p5.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <string>
#include <vector>
void print_comma(std::vector<std::string> const &input)
{ //prints the elements in order with a comma in between
    //using the index operator with 'at'
    //(for point 5)
    for (int i = 0; i < input.size() - 1; i++)
        std::cout << input.at(i) << ',';
    std::cout << input.at(input.size() - 1);
}

void print_semicolon(std::vector<std::string> const &input)
{
    //prints the elements in order with a semicolon in between
    //using an iterator
    //(for point 6)
    for (auto iterator = std::begin(input);
         iterator < std::end(input); iterator++)
    { //I implemented the iterator using type inference
        if (iterator != std::end(input) - 1)
            std::cout << *iterator << ';';
        else
            std::cout << *iterator;
    }
}
void print_space(std::vector<std::string> const &input)
{ //prints the elements in backwards order with a space in between
    //using an iterator
    //(for point 7)
    for (auto iterator = std::end(input) - 1;
         iterator >= std::begin(input); iterator--)
    { //type inference
        if (iterator != std::begin(input))
            std::cout << *iterator << ' ';
        else
            std::cout << *iterator;
    }
}
int main()
{
    std::vector<std::string> string_vector;
    std::string word;

    while (1)
    {
        std::getline(std::cin, word);
        if (word == "END") //condition which ends the loop
            break;
        else
        {
            string_vector.push_back(word);
        }
    }
    if (string_vector.at(1) != "\n" && string_vector.at(4) != "\n")
    { //swapping the two elements, if possible
        std::swap(string_vector[1], string_vector[4]);
    }
    else
    {
        std::cout << "no can do! One or both don't exist.";
    }
    string_vector[string_vector.size() - 1] = "???";
    //replacing the last element with '???'
    print_comma(string_vector); //calling all the print functions
    std::cout << '\n';
    print_semicolon(string_vector);
    std::cout << '\n';
    print_space(string_vector);
    return 0;
}