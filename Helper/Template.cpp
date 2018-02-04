
#include <iostream> 
#include <string> 

using namespace std;

int main() 
{
    string str;

    int hist[][]  = {{0, 0},
                     {1, 0},
                     {2, 0},
                     {3, 0},
                     {4, 0},
                     {5, 0},
                     {6, 0},
                     {7, 0},
                     {8, 0},
                     {9, 0}};

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        hist['0' - str[i]][1]++;
    }

     or(int i = 0; i <= 9; i++)
     {
         cout << hist[i][1] << endl;
     }
    
    
    return 0;
}