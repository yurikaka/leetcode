//179. Largest Number
//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.


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

bool cmp(string p, string q){
    return p+q > q+p;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for (auto i : nums)
            s.push_back(to_string(i));
        sort(s.begin(),s.end(),cmp);
        string result = "";
        for (auto i : s)
            result += i;
        while (result[0] == '0' && result.size()>1)
            result.erase(result.begin());
        return result;
    }
};

int main() {
    Solution s;
    return 0;
}

