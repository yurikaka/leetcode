//212. Word Search II
//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
//
//For example,
//        Given words = ["oath","pea","eat","rain"] and board =
//
//[
//['o','a','a','n'],
//['e','t','a','e'],
//['i','h','k','r'],
//['i','f','l','v']
//]
//Return ["eat","oath"].
//Note:
//        You may assume that all inputs are consist of lowercase letters a-z.


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

struct trienode{
    trienode * next[26] = {NULL};
    string w;
};

class Solution {
public:
    void ff(vector<vector<char>>& board, int i, int j, trienode *p, vector<string>& r){
        char c = board[i][j];
        if (c == '!' || !p->next[c-'a'])
            return;
        p = p->next[c-'a'];
        if (p->w.size()){
            r.push_back(p->w);
            p->w.clear();
        }
        board[i][j] = '!';
        if (i)
            ff(board,i-1,j,p,r);
        if (j)
            ff(board,i,j-1,p,r);
        if (i != board.size()-1)
            ff(board,i+1,j,p,r);
        if (j != board[0].size()-1)
            ff(board,i,j+1,p,r);
        board[i][j] = c;
    }
    trienode* build(vector<string>& words){
        trienode *r = new trienode;
        for (string w : words){
            trienode *p = r;
            for (char c : w){
                if (!p->next[c-'a'])
                    p->next[c-'a'] = new trienode;
                p = p->next[c-'a'];
            }
            p->w = w;
        }
        return r;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> r;
        trienode *root = build(words);
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                ff(board,i,j,root,r);
        return r;
    }
};

int main() {
    return 0;
}

