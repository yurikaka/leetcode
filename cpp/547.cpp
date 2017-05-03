//547. Friend Circles
//There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
//
//Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
//
//Example 1:
//Input:
//[[1,1,0],
//[1,1,0],
//[0,0,1]]
//Output: 2
//Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
//The 2nd student himself is in a friend circle. So return 2.
//Example 2:
//Input:
//[[1,1,0],
//[1,1,1],
//[0,1,1]]
//Output: 1
//Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
//        so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
//Note:
//        N is in range [1,200].
//M[i][i] = 1 for all students.
//If M[i][j] = 1, then M[j][i] = 1.


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

bool cmp(string p, string q){
    return p.size() < q.size();
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        unsigned int z = 0;
        int n = M.size(), r = 0;
        queue<int> q;
        int reach[n] = {0};
        for (int i = 0; i < n; ++i){
            if (reach[i])
                continue;
            reach[i] = 1;
            for (int j = 0; j < n; ++j){
                if (M[i][j] && !reach[j]){
                    q.push(j);
                    reach[j] = 1;
                }
            }
            while (q.size()){
                int x = q.front();
                q.pop();
                for (int j = 0; j < n; ++j){
                    if (M[x][j] && !reach[j]){
                        q.push(j);
                        reach[j] = 1;
                    }
                }
            }
            ++r;
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
