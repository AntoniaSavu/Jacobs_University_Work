/*
CH-231-A
a2_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/

#include <iostream>
#include <stdio.h>
#include <limits>
#include <cfloat>
#include "WindGauge.h"
#include <deque>
WindGauge::WindGauge(int period)
{ //makes the period be equal to 12
    //given the constructor declaration
    this->period = period;
}
void WindGauge::currentWindSpeed(int speed)
{
    if (wind_speeds.size() >= this->period)
        //if there is more than 12 speeds registered at the time
        wind_speeds.pop_front();  //pop the oldest one
    wind_speeds.push_back(speed); //and regardless, add a new one
}
int WindGauge::highest() const
{ //simple iteration that searches for the biggest value
    double max_wind = DBL_MIN;
    for (auto it = wind_speeds.begin(); it != wind_speeds.end(); it++)
        if (*it > max_wind)
            max_wind = *it;
    return max_wind;
}
int WindGauge::lowest() const
{ //simple iteration that searches for the smallest value
    double min_wind = DBL_MAX;
    for (auto it = wind_speeds.begin(); it != wind_speeds.end(); it++)
        if (*it < min_wind)
            min_wind = *it;
    return min_wind;
}
int WindGauge::average() const
{ //simple iteration that sums up all the values, then divides it by
    //the number of elements
    int average = 0, size = wind_speeds.size();
    for (auto it = wind_speeds.begin(); it != wind_speeds.end(); it++)
        average += *it;
    average /= size;
    return average;
}
void WindGauge::dump()
{ //the dump function which simply prints the highest, average and lowest values
    // that are being stored at the moment
    std::cout << "The highest speed is: " << highest() << ".\n";
    std::cout << "The average speed is: " << average() << ".\n";
    std::cout << "The lowest speed is: " << lowest() << ".\n\n";
}