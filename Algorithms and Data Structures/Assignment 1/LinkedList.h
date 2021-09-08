/*
CH-231-A
LinkedList.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
template <typename T>
struct Element
{
    T data;
    struct Element<T> *next;
    struct Element<T> *previous;
}; //creating an element of the list using struct
template <typename T>
class DLL
{ //doubly linked list, where every
    //element has the form of a struct defined above
private:
    Element<T> *start;
    Element<T> *end;
    int number; //size of list

public:
    DLL();
    ~DLL();

    int amount_of_elements();
    T return_without_del_first();
    T return_without_del_last();
    T return_del_first();
    T return_del_last();
    void add_first(T new_element);
    void add_last(T new_element);
    void print();
};
template <typename T>
DLL<T>::DLL()
{ //empty constructor

    start = nullptr;
    end = nullptr;
    number = 0;
}
template <typename T>
DLL<T>::~DLL()
{ //destructor, deleting each element of the list
    Element<T> *aux = this->start;
    Element<T> *current_el;
    for (int i = 0; i < number; i++)
    {
        current_el = aux;
        aux = aux->next;
        delete current_el;
    }
}
template <typename T>
T DLL<T>::return_without_del_first()
{ //returning the first element of the list
    //without deleting it

    if (this->start == nullptr)
    {
        std::cout << "No can do!List is empty\n";
        return -1;
    }
    return this->start->data;
}
template <typename T>
int DLL<T>::amount_of_elements()
{ //returns the size of the list
    return number;
}
template <typename T>
T DLL<T>::return_without_del_last()
{ //returning the last element of the list without
    //deleting it

    if (end == nullptr)
    {
        std::cout << "No can do!List is empty\n";
        return -1;
    }
    return this->end->data;
}
template <typename T>
T DLL<T>::return_del_first()
{ //return the first element of the list
    //while also deleting it

    if (start == nullptr)
    {
        std::cout << "No can do!List is empty";
        return -1;
    }
    Element<T> *aux;
    aux = this->start;
    T data = aux->data;
    this->start = aux->next;
    delete aux;
    this->start->previous = nullptr;
    return data;
}
template <typename T>
T DLL<T>::return_del_last()
{ //returning the last element of the list
    //while also deleting it

    if (end == nullptr)
    {
        std::cout << "No can do!List is empty";
        return -1;
    }
    Element<T> *aux = this->end;
    this->end->previous->next = nullptr;

    T data;
    data = aux->data;
    delete aux;
    return data;
}
template <typename T>
void DLL<T>::add_first(T new_data)
{ //adding an element at the beginning of the list

    number++;
    Element<T> *new_element = new Element<T>;
    new_element->data = new_data;
    new_element->previous = nullptr;
    new_element->next = this->start;

    if (number == 1)
    {
        this->start = new_element;
        this->end = new_element;
    }
    else
    {
        this->start->previous = new_element;
        this->start = new_element;
    }
}
template <typename T>
void DLL<T>::add_last(T new_data)
{ //adding an element at the end of the list

    number++;
    Element<T> *new_element = new Element<T>;
    new_element->data = new_data;
    new_element->previous = this->end;
    new_element->next = nullptr;

    if (number == 1)
    {
        this->start = new_element;
        this->end = new_element;
    }
    else
    {
        this->end->next = new_element;
        this->end = new_element;
    }
}
template <typename T>
void DLL<T>::print()
{ //implemented a print function to better
    //see the effect of the other methods
    std::cout << "The list: ";
    Element<T> *aux = this->start;
    while (aux != nullptr)
    {
        std::cout << aux->data << ' ';
        aux = aux->next;
    }
    std::cout << '\n';
}