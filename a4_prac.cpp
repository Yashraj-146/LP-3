#include <iostream>
#include <vector>
using namespace std;

class NQueenSolver {
private:
    int N;
    vector<vector<int>> board;

    bool isSafe(int row, int col) {
        // Check same column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 1) return false;

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1) return false;

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
            if (board[i][j] == 1) return false;

        return true;
    }

    // Recursive function to solve the N Queens problem
    bool solveNQueens(int row) {
        if (row >= N) return true; // base case: all queens placed

        for (int col = 0; col < N; col++) {
            // If position is empty and safe
            if (board[row][col] == 0 && isSafe(row, col)) {
                board[row][col] = 1;

                // Recurse for next row
                if (solveNQueens(row + 1)) return true;

                // Backtrack
                board[row][col] = 0;
            }
        }
        return false;
    }

    // Print the chessboard
    void printBoard() const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

public:
    // Constructor
    NQueenSolver(int size) : N(size), board(size, vector<int>(size, 0)) {}

    // Place the first queen manually
    void placeFirstQueen(int row, int col) {
        if (row < N && col < N) board[row][col] = 1;
    }

    // Start solving and print the result
    void solve() {
        if (solveNQueens(0))
            printBoard();
        else
            cout << "No solution exists for given placement." << endl;
    }
};

int main() {
    int N;
    cout << "Enter value of N: ";
    cin >> N;

    NQueenSolver solver(N);

    int firstRow, firstCol;
    cout << "Enter position of first Queen (row col): ";
    cin >> firstRow >> firstCol;

    solver.placeFirstQueen(firstRow, firstCol);
    solver.solve();

    return 0;
}