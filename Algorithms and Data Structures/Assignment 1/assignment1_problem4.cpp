/*
CH-231-A
a1_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <string>
#include <vector>
void print(std::vector<std::string> const &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        std::cout << input.at(i) << ' ';
    }
}
int main()
{
    std::vector<std::string> string_vector;
    std::string word;
    while (1)
    {
        std::cin >> word;
        std::cin.get();
        if (word == "END")
            break;
        else
        {
            string_vector.push_back(word);
        }
    }
    print(string_vector);
    return 0;
}