//37. Sudoku Solver
//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//Empty cells are indicated by the character '.'.
//
//You may assume that there will be only one unique solution.
//
//
//A sudoku puzzle...
//
//
//...and its solution numbers marked in red.

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>
#include <memory.h>
#include <set>
#include <deque>
#include <stack>
#include <bitset>

using namespace std;

class Solution {
public:
    int used[3][9][9];
    bool ss(vector<vector<char>>& board, int i, int j){
        if (i == 9)
            return true;
        if (j == 9)
            return ss(board,i+1,0);
        if (board[i][j] != '.')
            return ss(board,i,j+1);
        int t = i/3*3+j/3;
        for (int c = 0; c < 9; ++c){
            if (!used[0][i][c] && !used[1][j][c] && !used[2][t][c]){
                board[i][j] = c+'1';
                used[0][i][c] = used [1][j][c] = used[2][t][c] = 1;
                if (ss(board,i,j+1))
                    return true;
                board[i][j] = '.';
                used[0][i][c] = used [1][j][c] = used[2][t][c] = 0;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(used,0,sizeof(used));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (isdigit(board[i][j])){
                    int c = board[i][j] - '1', t = i/3*3+j/3;
                    used[0][i][c] = used[1][j][c] = used[2][t][c] = 1;
                }
        ss(board,0,0);
    }
};

int main() {
    return 0;
}