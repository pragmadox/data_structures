int main()
{
    watch stop_watch();
    stop_watch.start();
    for(int i=0; i<10000, ++i)
    {}
    stop_watch.stop();
    cout << stop_watch.seconds() << endl;
    cout << stop_watch.minutes() << endl;
    cout << stop_watch.hours() << endl;
    return 0;
}