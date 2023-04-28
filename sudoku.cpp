#include <iostream>
using namespace std;

const int N = 9;
const int SQN = 3;
int grid[N][N];

// Function to check if a given number can be placed in the given row and column
bool canPlace(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    int subrow = (row / SQN) * SQN;
    int subcol = (col / SQN) * SQN;
    for (int i = subrow; i < subrow + SQN; i++) {
        for (int j = subcol; j < subcol + SQN; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku grid
bool solve() {
    int row = -1, col = -1;
    bool isEmpty = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    if (!isEmpty) {
        return true;
    }
    for (int num = 1; num <= N; num++) {
        if (canPlace(row, col, num)) {
            grid[row][col] = num;
            if (solve()) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// Function to print the solved Sudoku grid
void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Enter the Sudoku grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    if (solve()) {
        cout << "Solved Sudoku grid:" << endl;
        printGrid();
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}
