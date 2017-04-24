//347. Top K Frequent Elements
//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//        Given [1,1,1,2,2,3] and k = 2, return [1,2].
//
//Note:
//        You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//Your algorithm's time complexity must be better than O(n log n), where n is the array's size.


#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <queue>

using namespace std;

unordered_map<int,int> m;
bool cmp(int p, int q){
    return m[p] > m[q];
}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        m.clear();
        for (auto it = nums.begin(); it != nums.end(); ++it){
            m[*it]++;
        }
        vector<int> t;
        for (auto it = m.begin(); it != m.end(); ++it)
            t.push_back(it->first);
        sort(t.begin(),t.end(),cmp);
        vector<int> r;
        for (int i = 0; i < k; ++i)
            r.push_back(*(t.begin()+i));
        return r;
    }
};
int main() {
    Solution s;

    return 0;
}

