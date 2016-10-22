#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    stringstream ss;
    int n;
    string user_string;

    while(getline(cin, user_string))
    {
    ss.clear();
    ss.str(" ");
    ss << user_string;
    while(ss >> n)
        cout << n << endl;
    }
return 0;
}
