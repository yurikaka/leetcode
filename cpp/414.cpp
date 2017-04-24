//414. Third Maximum Number
//Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
//
//Example 1:
//Input: [3, 2, 1]
//
//Output: 1
//
//Explanation: The third maximum is 1.
//Example 2:
//Input: [1, 2]
//
//Output: 2
//
//Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
//Example 3:
//Input: [2, 2, 3, 1]
//
//Output: 1
//
//Explanation: Note that the third maximum here means the third maximum distinct number.
//Both numbers with value 2 are both considered as second maximum.


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

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        unordered_set<int> s;
        int c = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it){
            if (s.find(*it) == s.end()) {
                ++c;
                s.insert(*it);
            }
            else continue;
            if (*it > first){
                third = second;
                second = first;
                first = *it;
            }
            else if (*it > second){
                third = second;
                second = *it;
            }
            else if (*it > third)
                third = *it;
        }
        if (c < 3)
            return first;
        return third;
    }
};
int main() {
    Solution s;

    return 0;
}

