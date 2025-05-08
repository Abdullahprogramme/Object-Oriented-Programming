#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    int n = board.size();

    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
void solveNQueensUtil(vector<vector<int>>& board, int row, vector<vector<vector<int>>>& result) {
    int n = board.size();
    if (row == n) {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1; // Place the queen
            solveNQueensUtil(board, row + 1, result); // Recur to place the rest of the queens
            board[row][col] = 0; // Backtrack
        }
    }
}

// Function to solve the N-Queens problem and return all possible solutions
vector<vector<vector<int>>> solveNQueens(int n) {
    vector<vector<vector<int>>> result;
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the board with 0s
    solveNQueensUtil(board, 0, result);
    return result;
}

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<vector<int>>> solutions = solveNQueens(n);

    cout << "Total solutions: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        printBoard(solution);
    }

    return 0;
}
