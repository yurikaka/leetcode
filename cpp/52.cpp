//52. N-Queens II
//Follow up for N-Queens problem.
//
//Now, instead outputting board configurations, return the total number of distinct solutions.


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
    int r;
    void ss(vector<string>& current, vector<int>& f1, vector<int>& f2, vector<int>& f3, int row, int n){
        if (row >= n) {
//            r.push_back(current);
            ++r;
            return;
        }
        for (int col = 0; col < n; ++col){
            if (!f1[col] && !f2[col+row] && !f3[n-1+col-row]){
                f1[col] = f2[col+row] = f3[n-1+col-row] = 1;
                current[row][col] = 'Q';
                ss(current,f1,f2,f3,row+1,n);
                f1[col] = f2[col+row] = f3[n-1+col-row] = 0;
                current[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> f1(n,0), f2(2*n-1,0), f3(2*n-1,0);
        vector<string> current(n,string(n,'.'));
//        vector<vector<string>> r;
        r = 0;
        ss(current,f1,f2,f3,0,n);
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
