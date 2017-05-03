//221. Maximal Square
//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//For example, given the following matrix:
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.


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
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), r= 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                int a = (i && j) ? matrix[i-1][j-1] : 0;
                int b = i ? matrix[i-1][j] : 0;
                int c = j ? matrix[i][j-1] : 0;
                matrix[i][j] = (matrix[i][j] - '0') ? min(a,min(b,c))+1 : 0;
                r = max(r,matrix[i][j] * matrix[i][j]);
            }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
