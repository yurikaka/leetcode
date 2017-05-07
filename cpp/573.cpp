//573. Squirrel Simulation
//There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.
//
//Example 1:
//Input:
//        Height : 5
//Width : 7
//Tree position : [2,2]
//Squirrel : [4,4]
//Nuts : [[3,0], [2,5]]
//Output: 12
//Explanation:
//
//        Note:
//All given positions won't overlap.
//The squirrel can take at most one nut at one time.
//The given positions of nuts have no order.
//Height and width are positive integers. 3 <= height * width <= 10,000.
//The given positions contain at least one nut, only one tree and one squirrel.

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
#include <math.h>

using namespace std;

class Solution {
public:
    int dist(vector<int>& p, vector<int>& q){
        return abs(p[0]-q[0])+abs(p[1]-q[1]);
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        vector<int> tonut,totree;
        for (auto i : nuts) {
            tonut.push_back(dist(i, squirrel));
            totree.push_back(dist(i, tree));
        }
        int l = nuts.size();
        int mini = INT_MAX;
        for (int i = 0; i < l; ++i){
            mini = min(mini,tonut[i] - totree[i]);
        }
        int r = 0;
        for (auto i : totree){
            r += 2 * i;
        }
        return r+mini;
    }
};

int main() {
    return 0;
}