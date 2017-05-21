//594. Longest Harmonious Subsequence My SubmissionsBack To Contest
//We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
//
//Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
//
//Example 1:
//Input: [1,3,2,2,5,2,3,7]
//Output: 5
//Explanation: The longest harmonious subsequence is [3,2,2,2,3].
//Note: The length of the input array will not exceed 20,000.

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

long long M = 1000000007;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        int l = nums.size();
        for (int i = 0; i < l; ++i)
            m[nums[i]]++;
        int r = 0;
        for (auto i = m.rbegin(); i != m.rend(); ++i)
            if (m.count(i->first+1))
                r = max(r,i->second+m[i->first+1]);
        return r;
    }
};

int main(){

}