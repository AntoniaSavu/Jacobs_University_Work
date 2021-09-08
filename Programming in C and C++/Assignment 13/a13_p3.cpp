/*
CH-230-A
a13_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <fstream>
std::ofstream g("concatn.txt", std::ios::binary);
//file we are going to copy to
int main()
{
    int n;
    char file_name[1000];
    std::cin >> n;
    std::cin.get();
    //empty space because otherwise it will consider enter the first string
    for (int i = 0; i < n; i++)
    {
        std::cin.getline(file_name, 1000);
        //reading file name
        std::ifstream f(file_name, std::ios::binary);
        //making it our input file
        g << f.rdbuf();
        //rdbuf returns a pointer to the stream buffer object
        //therefore the content of the buffer will be copied
        //into our output file
        g << "\n";
    }

    return 0;
}