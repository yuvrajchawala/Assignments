#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

int knapSack(vector<int> &weights,vector<int> &profits,int n,int capacity)
{
    int i,w;//two pointers nof the dp array;
    vector<vector<int> > dp(n+1,vector<int>(capacity+1));
    vector<int> taken(n);

    for(i=0;i<n+1;i++)
    {
        for(w=0;w<capacity+1;w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w] = 0;
            }
            else if(weights[i-1]<=w)
            {
                dp[i][w] = max(dp[i-1][w],(profits[i-1]+dp[i-1][w-weights[i-1]]));
            }
            else
            {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    int maxi = dp[n][capacity];
    

    return dp[n][capacity];
}

int main()
{
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    vector<int> profits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
    }

    int capacity;
    cin >> capacity;

    cout << knapSack(weights,profits,n,capacity);

}
