#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

bool solveRec(string &s,string &p,int i,int j)
{
    //base case
    if(i<0 && j<0)//thsi menas that bothe the string anf pattern consumed completely menas pattern is matched.
    {
        return true; 
    }

    if(i>=0 && j<0)//string not consumed properly, but the pattern is consumed
    {
        return false;
    }

    if(i<0 && j>=0)//string consumed properly, but pattern is not
    {
        for(int k=0;k<=j;k++)
        {
            if(p[k]!='*')
            {
                return false;
            }
        }
        return true;
    }

    //if match occcurs
    //two possibilties of match
    if(s[i]==p[j] || p[j]=='?')
    {
        return solveRec(s,p,i-1,j-1);
    }
    else if(p[j]=='*')//if star occurs two casses
    {
        return (solveRec(s,p,i,j-1) || solveRec(s,p,i-1,j));//(when we chnage the * with empty string || when we cchange * with *__ pattern required to match)
    }
}

bool solveMemo(string &s,string &p,int i,int j,vector<vector<int> > &dp)
{
    if(i<0 && j<0)
    {
        return true; 
    }
    if(i>=0 && j<0)
    {
        return false;
    }

    if(i<0 && j>=0)
    {
        for(int k=0;k<=j;k++)
        {
            if(p[k]!='*')
            {
                return false;
            }
        }
        return true;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    if(s[i]==p[j] || p[j]=='.')
    {
        dp[i][j] = solveRec(s,p,i-1,j-1);
        return dp[i][j];
    }
    else if(p[j]=='*')
    {
        dp[i][j] = (solveRec(s,p,i,j-1) || solveRec(s,p,i-1,j));
        return dp[i][j];
    }
    else
    {
        return false; 
    }
}


bool isMatch(string s,string p)
{
    int n = s.length();
    int m = p.length();

    //recuresive solution
    // return solveRec(s,p,n-1,m-1);

    //memoizing the solution
    vector<vector<int> > dp(n,vector<int>(m,-1));//creating a 2-d dp array as two parameters are changing, one is the char in string s and other one in p.
    return solveMemo(s,p,n-1,m-1,dp);
}
 
int main()
{
    string s,p;
    cin >> s >> p;

    cout << isMatch(s,p);
}