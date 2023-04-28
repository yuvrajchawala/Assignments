#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int helper(int n,vector<int> &dp)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    dp[n] = helper(n-1,dp)+helper(n-2,dp)+helper(n-3,dp);
    return dp[n];
}

int numWays(int n)
{
    //creating a dp vector to store the value of recursive calls, to avoid repititive calls 
    vector<int> dp(n+1,-1);
    int ans = helper(n,dp);
    return ans;
}
 
int main()
{
    int n;
    cin >> n;

    cout << numWays(n) << endl;
}
