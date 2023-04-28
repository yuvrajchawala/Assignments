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
#include <set>
using namespace std;

//THE APPROACH USED - we will go at every index of the strign if its a number we will take it as it is, but if it is a character we will make it capaital it is not or make it lowercase if its uppercase.

//in this we will generate many combinations, so here we will use the INCLUSION-EXCLUSION approach (but here we will capitalize or not capitalize the chosen index).

//to avoid repititive ans we will use a set data structure we will store each answer only once.

void helper(string s,set<string> &ans,int index,string ds)
{
    //if the index we are currently on is the length hence we have traversed the string completely so just store the ans now.
    if(index==s.length())
    {
        ans.insert(ds);
        return;
    }
    
    //if its a number use it as it is.
    if(s[index]-'0'>=0 && s[index]-'0'<=9)
    {
        helper(s,ans,index+1,ds+s[index]);
    }

    //both characters are now ready.
    char u = toupper(s[index]);
    char l = tolower(s[index]);
    
    //now once we will use the lower case of it, and once we will call it with the upper case.
    helper(s,ans,index+1,ds+l);
    helper(s,ans,index+1,ds+u);
}

void allStrings(string s,vector<string> &p)
{
    //making a empty strign ds which will eihter contain the capitalized character or the not capitalized character.
    string ds = "";
    
    //we will store the answers in a set to avoid repitions and then tranfer it to the vector later.
    set<string> ans;
    
    //this the main function where we pass the strings input, the set which will contian the input, the index on which operations would be performed,and the string which will be used for the purpose.
  
    helper(s,ans,0,ds);
   
    for(auto it : ans)
    {
        p.push_back(it);
    }
}
 
int main()
{
    string s;
    cin >> s;

    
    //this vector p will get all the answers in it .
    vector<string> p;
    allStrings(s,p);

    for(auto i : p)
    {
        cout << i << endl;
    }
    
}