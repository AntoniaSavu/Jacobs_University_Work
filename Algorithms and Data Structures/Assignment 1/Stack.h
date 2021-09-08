/*
CH-231-A
Stack.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>

template <typename T>
class Stack
{
private:
    int size, index;
    T *array;

public:
    Stack()
    {
        index = -1;
        size = 10;
        //initialising the size with 10 in case no parameter is given
        array = new T[size];
        //dynamically allocating array
    }
    Stack(const Stack &newstack)
    { //copying a stack using the copy constructor
        this->size = newstack.size;
        this->array = new T[newstack.size];
        this->index = newstack.index;
        for (int i = 0; i < newstack.size; i++)
            this->array[i] = newstack.array[i];
    }
    Stack(int size)
    { //initialising a stack given a specific size
        this->index = -1;
        this->size = size;
        array = new T[size];
    }
    bool push(T element)
    { //pusing an element in the stack
        if (this->index == this->size - 1)
        { //if the index is as big as the size
            //(-1 because of the iteration difference)
            //then we can't push more into the stack
            std::cout << "no can do!\n";
            return false;
        }
        else
        {

            this->array[++index] = element;
            return true;
        }
    }
    bool pop(T &out)
    { //popping an element
        if (this->index == -1)
        { //if the stack is empty, we cannot pop anything
            std::cout << "no can do!\n";
            return false;
        }
        else
        {

            out = this->array[index];
            this->array[index--] = 0;
            return true;
        }
    }

    T back(void)
    { //method that returns the top of the stack
        return this->array[this->index];
    }
    int getNumEntries()
    { //method that returns the amount of elements in the stack
        return this->index + 1;
    }
    ~Stack()
    { //destructor, deallocating memory
        delete[] this->array;
    }
    void print()
    { //made a simple print function in order to visualise things better
        for (int i = 0; i < this->size; i++)
            std::cout << this->array[i] << ' ';
        std::cout << '\n';
    }
};