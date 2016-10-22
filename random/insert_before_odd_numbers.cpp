#include<algorithm>

bool odd(int n)
{
    return n%2;
}

void insert_before_odd_numbers( vector<int> &v)
{
    vector<int>:::iterator p=v.begin();
    while(p!=v.end())
    {
        p = find_if(p, v.end(), odd)
        if(p!=v.end())
        {
            p=v.insert(p,-1);
            p+=2;
        }
    }
}