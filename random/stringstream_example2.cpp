#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    stringstream ss;
    int num;
    string user_string, w;
    char ch;

    while(cin >> user_string)
    {
        user_string.resize(user_string.size()-1);
        ss.clear();
        ss.str(" ");
        ss << user_string;
        ss >> ch >> num >> ch >> w;
        cout << "num = " << num;
        cout << "<-->" << "w: ," << w << ",";
    }
return 0;
}
