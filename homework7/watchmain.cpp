#include <iostream>
#include <cstdlib>
#include <ctime>
#include "watch.h"
using namespace std;

int main()
{
    Watch stop_watch;
    stop_watch.start();
    for(int i=0; i<1000000000; ++i)
    {}
    stop_watch.stop();
    cout << stop_watch.seconds() << endl;
    cout << stop_watch.minutes() << endl;
    cout << stop_watch.hours() << endl;
    return 0;
}