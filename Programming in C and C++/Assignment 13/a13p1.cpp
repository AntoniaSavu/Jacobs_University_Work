/*
CH-230-A
a13_p1.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <fstream>
#include <iostream>
#include <cstring>

char file_name[200], first_part[200], extension[200], final_name[207];
//i declared these globally so they are empty
//otherwise i'd have to do it manually in main
const char copy[] = "_copy"; //the part we concatenate, constant
int main()
{
    int ok = 0, m = 0, n = 0;
    std::cin.getline(file_name, 200);
    //reading the file name
    for (int i = 0; file_name[i]; i++)
    { //looping thorugh the string
        if (file_name[i] == '.')
        {           //when we reach the dot(extension starts)
            ok = 1; //i make sure we can't add to the first part anymore
            extension[m++] = file_name[i];
            //and i add the dot to the extension string
        }
        else
        {
            if (ok)
                extension[m++] = file_name[i];
            // i add the characters to the extension string
            else

                first_part[n++] = file_name[i];
            //otherwise, we still have not reached the dot,
            // so it is still the first part
        }
    }
    strcat(final_name, first_part);
    strcat(final_name, copy);
    strcat(final_name, extension);
    //finally, concatenating everything into a new string
    std::ifstream f(file_name);
    std::ofstream g(final_name);
    //and making that new string the name of the ofstream files
    g << f.rdbuf();
    //copying in the ofstream file the contents of the ifstream file

    return 0;
}