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
 
int main()
{
    int n;
    cin >> n;

    vector<int> vec;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    for(auto i : vec)
    {
        s.insert((i*i));
    }
    vector<int> ans;
    for(auto i : s)
    {
        ans.push_back(i);
    }
    for(auto i : ans)
    {
        cout << i << " ";
    }
}
