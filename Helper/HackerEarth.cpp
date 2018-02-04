#include "./../Include/CommonInc.h"


#include <iostream> 
#include <string> 

using namespace std;

int tmain() 
{
    string str;

    int hist[][2]  = {{0, 0},
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
      //   cout << str[i] - '0';
        hist[str[i] - '0'][1]++;
    }

     for(int i = 0; i <= 9; i++)
     {
         cout << hist[i][0] << " " << hist[i][1] << endl;
     }
    
    
    return 0;
}