#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define BLANK = " ";
#define BLOCK = BLANK + "\u2588" + BLANK;
#define EMPTY = BLANK + "\u25fd" + BLANK;
#define TRIANGLE = BLANK + "\u25b3" + BLANK;

int main()
{
    int n_1, n_2;
    stringstream ss;
    ss << 100 << ' ' << 200;
    ss >> n_1 >> n_2;
    cout << "n_1 = " << n_1 << endl;
    cout << "n_2 = " << n_2 << endl;
return 0;
}
