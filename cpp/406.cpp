//406. Queue Reconstruction by Height
//Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//
//Note:
//        The number of people is less than 1,100.
//
//Example
//
//        Input:
//[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
//Output:
//[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


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

bool cmp(pair<int, int> p, pair<int, int> q){
    return p.second < q.second || (p.second == q.second && p.first > q.first);
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<pair<int, int>> r;
        for (auto i : people){
            int cnt = 0;
            auto j = r.begin();
            for (; j != r.end(); ++j){
                if (j->first >= i.first)
                    ++cnt;
                if (cnt > i.second)
                    break;
            }
            r.insert(j,i);
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
