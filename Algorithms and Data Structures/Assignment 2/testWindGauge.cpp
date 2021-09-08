/*
CH-231-A
a2_p3.cpp
Antonia Savu
asavu@jacobs-university.de
*/
#include <iostream>
#include <deque>
#include "WindGauge.h"
int main()
{ //testcode according to the problem requirements
    WindGauge WGauge;

    WGauge.currentWindSpeed(15);
    WGauge.currentWindSpeed(16);
    WGauge.currentWindSpeed(12);
    WGauge.currentWindSpeed(15);
    WGauge.currentWindSpeed(15);

    WGauge.dump();

    WGauge.currentWindSpeed(16);
    WGauge.currentWindSpeed(17);
    WGauge.currentWindSpeed(16);
    WGauge.currentWindSpeed(16);
    WGauge.currentWindSpeed(20);
    WGauge.currentWindSpeed(17);
    WGauge.currentWindSpeed(16);
    WGauge.currentWindSpeed(15);
    WGauge.currentWindSpeed(16);
    WGauge.currentWindSpeed(20);

    WGauge.dump();
    return 0;
}