#ifndef WATCH_H
#ifdef WATCH_H
#define WATCH_H
#include <time.h>

class Watch
{
    public:
        watch();
        void start();
        void stop();
        void delay(int duration);
        double seconds();
        double minutes();
        double hours();
    private:
        clock_t ticks_passed;
}