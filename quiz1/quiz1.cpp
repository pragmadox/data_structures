#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;    

vector < vector<int> > v;
vector<int> sums;
int minimum_value = 0;

void read_data_file()
{

    vector<int> row;

    stringstream ss;

    int element;

    string line;

    string fileName;

    cout << "Enter the name of the data file with its extension: ";
    cin >> fileName;

    fstream myfile(fileName.c_str());
 
    if(myfile.is_open())
    {
        cout << "The data file is open.\n";

        while(getline(myfile,line))
        {
            ss.clear();
            ss.str ("");
            ss << line;

            while(ss >> element)
            {
                row.push_back( element );
            }
            v.push_back(row);
            row.clear();
        }
        myfile.close();
    }

    //If there is a problem opening the file, a message is displayed.
    else
    {
        cout << "Unable to open file.";
    }

}

void sum_rows()
{
    int row_sum = 0;
    for( int r = 0; r < v.size(); r++ )
    {
        for( int c = 0; c < v[r].size(); c++ )
        {
            row_sum = row_sum + v[r][c];
        }
        cout << row_sum << endl;
        sums.push_back(row_sum);
        row_sum = 0;
    }
}

void get_min()
{
    minimum_value = sums[0];
    
    for(int i=0; i <= (sums.size()-1); i++)
    {
        if(sums[i]<minimum_value)
            minimum_value=sums[i];
    }
    
}
    

void final_vector()
{
    for( int r = 0; r < v.size(); r++ )
    {
        if ( sums[r] != minimum_value )
        {
                v[r].resize(0);
        }
        cout << endl;
    }
}

void print_vector()
{
    for( int r = 0; r < v.size(); r++ )
    {
        for( int c = 0; c < v[r].size(); c++ )
        {
            cout << setw(3) << v[r][c];
        }
        cout << endl;
    }
}

int main()
{
    read_data_file();
    sum_rows();
    get_min();
    final_vector();
    print_vector();
}
