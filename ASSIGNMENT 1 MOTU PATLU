#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
 
int main()
{
    int n;
    cin >> n;

    //first we will remove the bricks until we reach the last brick where the winner can be decided

    //since in the ith round PATLU - removes i bricks and MOTU - removes (2*i) bricks, so collectively in every i th roung TOTAL - (3*i) bricks are removed.

    //so we will calculate the round in which the last bricks would be removed by finding out the round after which either bricks becomes zero or negative.

    int i = 1;
    while((n-(3*i))>0)
    {
        n-=(3*i);
        i++;
    }
    //(i-1) the round
    //and (n+3i) bricks remaining.


    //now we have found out htat roung then we can check who removes the last brick by removing the bricks,
    
    //IF AFTER REMOVING i BRICKS , if the no. of bricks is greater than 0 HENCE motu will have to remov the last, else if it is 0 menas patlu has removed the last brik already and WON.

    if(n-i>0)
    {
        cout << "Motu" << endl;
    }
    else 
    {
        cout << "Patlu" << endl;
    }

}
