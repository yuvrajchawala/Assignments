/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool isPalindrome(string s)
{
    //Maintain two pointers which will traverse the string the string from start and end each.
    
    int n = s.length();//length of given string
    
    int i = 0;//pointer from start
    int j = n-1;//pointer from end

    while(i<=j)//while both do not cross each other.
    {
        if(s[i]!=s[j])//just check if any of the two pairs are not equal hence it is not a palindrome.
        {
           return false;
        }
        i++;
        j--;
    }
    
    //if the string is traversed cmpletey means all pairs have character and form a palindrome.
    return true;
}
 
int main()
{
    string s;
    cin >> s;

    cout << isPalindrome(s) << endl;
   
}
