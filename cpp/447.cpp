//447. Number of Boomerangs
//Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//
//Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).
//
//Example:
//        Input:
//[[0,0],[1,0],[2,0]]
//
//Output:
//2
//
//Explanation:
//        The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]


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

using namespace std;

class Solution {
public:
    int dist(pair<int, int> p, pair<int, int> q){
        return (p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second);
    }
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int l = points.size(), result = 0;
        unordered_map<int,int> m;
        for (int i = 0; i < l; ++i){
            m.clear();
            for (int j = 0; j < l; ++j){
                if (i == j)
                    continue;
                m[dist(points[i],points[j])]++;
            }
            for (auto j : m){
                if (j.second > 1)
                    result += j.second * (j.second-1);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

