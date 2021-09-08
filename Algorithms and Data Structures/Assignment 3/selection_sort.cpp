/*
CH-231-A
a3_p2.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <chrono>
#include <fstream>
/*
As you will notice in the output, the numbers are bad.
I'm 95% sure it is not because of the code, but because I am 
using windows OS.I tried a code that worked 
perfectly on linux on my pc and it did not work.
The clocks from microsoft dont have a high enough resolution
to have an accurate read and this will show in the plot aswell.
Will try to get WSL running till next week. sorry!
*/
std::ofstream g("Output.txt");
int max_element(int a[])
{ //finding out the max element in an array
    int max = -2147483648;
    for (int i = 0; a[i]; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
int *random(int n)
{ //using srand to get  a random array of size n
    srand(time(NULL));
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % n;
    return a;
}
void Selectionsort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;
        if (min != i)
        {
            int aux = a[min];
            a[min] = a[i];
            a[i] = aux;
        }
    }
}
int main()
{
    int *a;
    for (int n = 0; n < 1000; n += 5)
    {

        a = random(n);
        //the worst case scenario for the selection sort is if the first element is the largest one
        //therefore, I am setting the the element at position 0 to take the largest value in the array
        a[0] = max_element(a);

        auto start = std::chrono::high_resolution_clock::now();
        Selectionsort(a, n);
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> worst = stop - start;
        //and then measuring the time it takes to sort it

        //best case scenario would be if the array is already sorted
        //as there is nothing that needs to be changed about it.
        //I am simply using the exact same array again which was
        //sorted previously, line 55
        start = std::chrono::high_resolution_clock::now();
        Selectionsort(a, n);
        stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> best = stop - start;

        //in order to calculate the average , i am doing the sort 20 times and summing up those values
        //it is not the most accurate average, but doing this more times would take alot of execution time
        double sum = 0;
        for (int i = 0; i < 20; i++)
        {
            a = random(n);
            auto start2 = std::chrono::high_resolution_clock::now();
            Selectionsort(a, n);
            auto stop2 = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double, std::milli> total = stop2 - start2;
            sum = sum + total.count();
        }

        double average = 0.0;
        average = sum / 20.0;

        g << n << " " << worst.count() << " " << best.count() << " " << average << '\n';
        //then simply printing them in a  file, as it is easier to manage
    }
    return 0;
}