//79. Word Search
//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
//For example,
//        Given board =
//
//[
//['A','B','C','E'],
//['S','F','C','S'],
//['A','D','E','E']
//]
//word = "ABCCED", -> returns true,
//word = "SEE", -> returns true,
//word = "ABCB", -> returns false.


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
#include <stack>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    bool ff(vector<vector<char>>& board, string word, int x, int y, int s){
        if (s >= word.size())
            return true;
        if (x < 0 || x >= board.size() || y < 0 || y>=board[0].size())
            return false;
        if (board[x][y] == word[s++]){
            char c = board[x][y];
            board[x][y] = '!';
            bool r = ff(board,word,x-1,y,s) || ff(board,word,x+1,y,s) || ff(board,word,x,y-1,s) || ff(board,word,x,y+1,s);
            board[x][y] = c;
            return r;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (ff(board,word,i,j,0))
                    return true;
        return false;
    }
};

int main() {
    return 0;
}

