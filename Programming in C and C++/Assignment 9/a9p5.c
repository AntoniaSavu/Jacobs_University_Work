/*CH-230-A
a9_p4.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int x, tries = 0;
    int a = rand() % 100 + 1; //randomly choosing a number from 1 to 100
    char s[500];
    cout << "What is your name?";
    cin.getline(s, 500); //the player inputs their name

    cout << "Guess the number";
    while (1)
    {
        cin >> x;
        tries++; //incrementing the number of tries at each pass
        if (x == a)
        {
            cout << "Good job!" << '\n';
            break;
            //if the number was guessed, the loop ends
        }
        else
        {
            if (x < a)
                cout << "Too low";
            else

                cout << "Too high";
            //otherwise printing if the number is lower or higher
        }
    }
    cout << "Guessed out of " << tries << " tries";
    //printing the number of tries it took for the player to guesss
    return 0;
}