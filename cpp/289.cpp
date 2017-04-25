//289. Game of Life
//According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
//Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//
//Any live cell with fewer than two live neighbors dies, as if caused by under-population.
//Any live cell with two or three live neighbors lives on to the next generation.
//Any live cell with more than three live neighbors dies, as if by over-population..
//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//Write a function to compute the next state (after one update) of the board given its current state.
//
//Follow up:
//Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
//In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>

using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                int cnt = 0;
                if (i)
                    cnt += board[i-1][j]%10;
                if (j)
                    cnt += board[i][j-1]%10;
                if (i != m-1)
                    cnt += board[i+1][j]%10;
                if (j != n-1)
                    cnt += board[i][j+1]%10;
                if (i && j)
                    cnt += board[i-1][j-1]%10;
                if (i && j != n-1)
                    cnt += board[i-1][j+1]%10;
                if (i != m-1 && j)
                    cnt += board[i+1][j-1]%10;
                if (i != m-1 && j != n-1)
                    cnt += board[i+1][j+1]%10;
                if (board[i][j]){
                    if (cnt == 2 || cnt == 3)
                        board[i][j] += 10;
                }
                else {
                    if (cnt == 3)
                        board[i][j] += 10;
                }
            }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] /= 10;
    }
};
int main() {
    Solution s;

    return 0;
}

