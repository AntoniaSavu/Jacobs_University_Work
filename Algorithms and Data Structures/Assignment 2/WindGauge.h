/*
CH-231-A
a2_p3.h
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <deque>
class WindGauge
{
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump();

private:
    std::deque<double> wind_speeds;
    //deque container to store the speeds
    int period;
    //the amount of values that need to be stored at a time
};
