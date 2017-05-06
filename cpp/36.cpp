//36. Valid Sudoku
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note:
//        A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

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
    bool isValidSudoku(vector<vector<char>>& board) {
        int used[3][9][9];
        memset(used,0,sizeof(used));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j){
                int c = board[i][j];
                if (isdigit(c)){
                    c = c - '0' - 1;
                    int t = i/3*3+j/3;
                    if (used[0][i][c]||used[1][j][c]||used[2][t][c])
                        return false;
                    used[0][i][c] = used[1][j][c] = used[2][t][c] = 1;
                }
            }
        return true;
    }
};

int main() {
    return 0;
}