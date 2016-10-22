#include<iostream>
#include<cstdlib>
#include "watch.h"
using namespace std;

watch::watch()
{
    ticks_passed=clock();
}

void watch::start()
{
    ticks_passed=clock();
}

void watch::stop()
{
    ticks_passed=clock()-ticks_passed;
    if(ticks_passed==clock_t(-1))
    {
        cout << "clock overflow" << endl;
        exit();
    }
}

void watch::delay()
{
    for(int i=0; i<duration; ++i)
    {};    
}

double watch::seconds()

{
    return double(ticks_passed)/CLOCK_PER_SEC;
}

double watch::minutes()
{
    return double(ticks_passed)/CLOCK_PER_SEC/60;
}

double watch::hours()
{
    return double(ticks_passed)/CLOCK_PER_SEC/60/60;
}