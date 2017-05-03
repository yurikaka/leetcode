//120. Triangle
//Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//   [2],
//  [3,4],
// [6,5,7],
//[4,1,8,3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//        Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


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

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if (row == 1)
            return triangle[0][0];
        vector<int> temp;
        for (int i = row-1; i > 0; --i){
            if (i != row-1){
                for (int j = 0; j < triangle[i].size(); ++j)
                    triangle[i][j] += temp[j];
            }
            temp.clear();
            for (int j = 0; j < triangle[i].size()-1; ++j)
                temp.push_back(min(triangle[i][j],triangle[i][j+1]));
        }
        return triangle[0][0] + temp[0];
    }
};

int main() {
    Solution s;
    return 0;
}
