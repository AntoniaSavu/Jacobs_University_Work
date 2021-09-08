/*
CH-231-A
LinkedList.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include "LinkedList.h"
#include <iostream>
int main()
{
    DLL<int> List;
    //Declaring an instace of a doubly linked list of ints

    int First_element = List.return_without_del_first();
    int Last_element = List.return_without_del_last();
    //as we can notice by running the program, this won't work
    //because the list is empty

    List.add_last(1);
    List.add_first(21);
    List.add_last(15);
    List.print();
    //when printing, we can see that the adding methods work as intended

    int Size = List.amount_of_elements();
    std::cout << "The list currently has " << Size << " elements.\n";
    First_element = List.return_del_first();
    Last_element = List.return_del_last();
    std::cout << "The first element of the list used to be "
              << First_element << " and the last element used to be "
              << Last_element << '\n';
    List.print();
    //printing the list again to show
    // that the elements have been successfully deleted
    std::
            cout
        << "------------------------------------------------------\n";

    //exact same thing but with chars

    DLL<char> List_char;
    //Declaring an instace of a doubly linked list of chars

    char First_element_char = List_char.return_without_del_first();
    char Last_element_char = List_char.return_without_del_last();
    //as we can notice by running the program, this won't work
    //because the list is empty

    List_char.add_last('A');
    List_char.add_first('I');
    List_char.add_last('+');
    List_char.print();
    //when printing, we can see that the adding methods work as intended

    Size = List_char.amount_of_elements();
    std::cout << "The list currently has " << Size << " elements.\n";
    First_element_char = List_char.return_del_first();
    Last_element_char = List_char.return_del_last();
    std::cout << "The first element of the list used to be "
              << First_element_char << " and the last element used to be "
              << Last_element_char << '\n';
    List_char.print();
    //printing the list again to show
    // that the elements have been successfully deleted

    return 0;
}