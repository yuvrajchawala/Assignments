#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<pair<int,int> > ans;//this will store all the pair of answers where the x is found in the matrix.

void search(vector<vector<int> > &matrix,int n_rows,int n_cols,int x)
{
    //we can observe that if we choose the corner elements all the elemnts down the row are grater than it ,and all elements along the colums are less than it.
    int row = 0;
    int col = n_cols-1;

//while the pointer does not goe out of the matrix search in the matrix
    while(row<n_rows && col>=0)
    {
        if(matrix[row][col]==x)//if found than come daignol acroos downwards.
        {
            pair<int,int> p;
            p.first = row;
            p.second = col;
            ans.push_back(p);
            row++;
            col--;
        }
        else if(matrix[row][col]>x)
        {
            col--;
        }
        else 
        {
            row++;
        }
    }
}
 
int main()
{
    int n_rows,n_cols;
    cin >> n_rows >> n_cols;

    vector<vector<int> > matrix(n_rows,vector<int>(n_cols));
    for(int i=0;i<n_rows;i++)
    {
        for(int j=0;j<n_cols;j++)
        {
            cin >> matrix[i][j];
        }
    }

    int x;
    cin >> x;

    search(matrix,n_rows,n_cols,x);
    for(int i=0;i<ans.size();i++)
    {
        cout << "Element " << x << "is found at position (" << ans[i].first << "," << ans[i].second << ")" << endl;
    }
}
