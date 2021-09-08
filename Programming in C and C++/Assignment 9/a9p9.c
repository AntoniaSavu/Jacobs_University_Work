/*CH-230-A
a9_p9.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    const string s[] = {"computer", "television", "keyboard",
                        "laptop", "mouse", "cat", "dog",
                        "fox", "wolf", "tiger", "lion", "zebra", "elephant",
                        "ceetah", "jaguar", "panther", "giraffe"};
    //the array of strings with 17 words
    srand(static_cast<unsigned int>(time(0)));
    int tries = 0;

    string word, t, copy;
    word = s[rand() % 17]; //selecting a random word
    while (1)
    {

        cout << "Guess the word:";
        copy = word;
        //making a copy of it so i can swap the
        //vowels with _ without losing the initial word
        for (int i = 0; copy[i]; i++)
            if (strchr("AEIOUaeiou", copy[i]) != NULL)
                copy[i] = '_'; //swapping the vowels
        cout << copy << '\n';
        cin >> t;
        cin.get();
        tries++;         //incrementing the tries
        if (t == "quit") //breaking the loop if the player 'guesses' quit
            break;
        if (t == word)
        { //if the player guesses, the tries are written on the screen
            //and they are asked if they want to play again
            cout << "Tries: " << tries << '\n';
            cout << "Good job! Want to play again?" << '\n';
            cin >> t;
            cin.get();
            if (t == "quit") //if the answer is quit , the program ends
                break;
            else if (t == "yes")
            { //i asked the professor about this part with 'yes'
                // she said it was fine
                word = s[rand() % 17];
                //selecting another word
            }
        }
        else
            cout << "Wrong. Try again!" << '\n';
        //printing if the guess was wrong
    }
    return 0;
}
/* google reference:
http://www.cplusplus.com/forum/beginner/86721/
*/