#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

vector<vector<char>> board(9, vector<char>(9, '.')); // the main board.

void sudokuSolver(vector<vector<char>> &board)
{
    //trying to put every possible value at the empy index and trying out the solution
    solve(board);
}

bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')//searching for the empty places
                {
                    //once you find an empty position you will try out everyhting from 0 to 9
                    for(char c='1';c<='9';c++)
                    {
                        if(isValid(board,i,j,c))//this isValid will check wether we can place the char at that empty position or not
                        {
                            board[i][j] = c;
                            if(solve(board)==true)//ab i have solve a sub problem by filling one blank and now we are lopping again aftr making chnages to find other blank spot and solve that sub problem.
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';//vrna vapis se reset krdiya
                            }
                        }
                    }
                    return false;//kuch bhi kaam nhi aaya to false return.
                }
            }
        }
        return true;//means everthing is filled in the board.
    }


bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    // we have to complete 3 checks for a char to valid for an empty position

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c) // char already present in the row
        {
            return false;
        }
        if (board[row][i] == c) // char alrady present in the col
        {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // in submatrix we will use thsi formula to just iterate over the require submatrix in which the space is present.
        {
            return false;
        }
    }
    return true;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    sudokuSolver(board);
}