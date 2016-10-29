#ifndef WATCH_H
#define WATCH_H
#include <ctime>

class Watch
{
    public:
        Watch();
        void start();
        void stop();
        void delay(int duration);
        double seconds();
        double minutes();
        double hours();
    private:
        clock_t ticks_passed;
};

#endif