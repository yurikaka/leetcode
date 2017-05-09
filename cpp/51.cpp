//51. N-Queens
//The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
//Given an integer n, return all distinct solutions to the n-queens puzzle.
//
//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
//For example,
//        There exist two distinct solutions to the 4-queens puzzle:
//
//[
//[".Q..",  // Solution 1
//"...Q",
//"Q...",
//"..Q."],
//
//["..Q.",  // Solution 2
//"Q...",
//"...Q",
//".Q.."]
//]


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
    void ss(vector<vector<string>>& r, vector<string>& current, vector<int>& f1, vector<int>& f2, vector<int>& f3, int row, int n){
        if (row >= n) {
            r.push_back(current);
            return;
        }
        for (int col = 0; col < n; ++col){
            if (!f1[col] && !f2[col+row] && !f3[n-1+col-row]){
                f1[col] = f2[col+row] = f3[n-1+col-row] = 1;
                current[row][col] = 'Q';
                ss(r,current,f1,f2,f3,row+1,n);
                f1[col] = f2[col+row] = f3[n-1+col-row] = 0;
                current[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> f1(n,0), f2(2*n-1,0), f3(2*n-1,0);
        vector<string> current(n,string(n,'.'));
        vector<vector<string>> r;
        ss(r,current,f1,f2,f3,0,n);
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
