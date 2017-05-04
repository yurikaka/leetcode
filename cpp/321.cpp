//321. Create Maximum Number
//Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity.
//
//Example 1:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//return [9, 8, 6, 5, 3]
//
//Example 2:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//return [6, 7, 6, 0, 4]
//
//Example 3:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//return [9, 8, 9]


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
    bool gg(vector<int> nums1, vector<int> nums2, int m, int n){
//        int l = min(nums1.size() - m, nums2.size() - n), i;
//        for (i = 0; i < l; ++i) {
//            if (nums1[m + i] > nums2[n + i])
//                return true;
//            else if (nums1[m + i] < nums2[n + i])
//                return false;
//        }
//        if (n+i == nums2.size())
//            return true;
//        else
//            return false;
        while (m<nums1.size() && n<nums2.size() && nums1[m]==nums2[n]){
            ++m;++n;
        }
        return n == nums2.size() || (m < nums1.size() && nums1[m] > nums2[n]);
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2){
        vector<int> r;
//        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
//        while (i < m || j < n){
//            if (i >= m){
//                r.push_back(nums2[j++]);
//                continue;
//            }
//            if (j >= n){
//                r.push_back(nums1[i++]);
//                continue;
//            }
//            if (gg(nums1,nums2,i,j))
//                r.push_back(nums1[i++]);
//            else
//                r.push_back(nums2[j++]);
//        }
//        return r;
        for (int i = 0, j = 0, l = 0; l < nums1.size()+nums2.size(); ++l)
            r.push_back(gg(nums1,nums2,i,j)?nums1[i++]:nums2[j++]);
        return r;
    }
    vector<int> mm(vector<int>& nums, int k){
        if (k==0)
            return vector<int>{};
        vector<int> r;
        int i = 0, maxx, p, l = nums.size();
        while (k > 0){
            maxx = nums[i];
            p = i;
            for (int j = i+1; l-j >= k; ++j)
                if (nums[j] > maxx){
                    maxx = nums[j];
                    p = j;
                }
            r.push_back(maxx);
            i = p+1;
            --k;
        }
        return r;
        // int n = nums.size();
        // for (int i = 0, j = 0; i < n; ++i){
        //     while (n-i+j>k&&j>0&&r[j-1]<nums[i])
        //         --j;
        //     if (j < k)
        //         r[j++] = nums[i];
        // }
        // return r;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> r1, r = vector<int>(k,-1);
        int m = nums1.size(), n = nums2.size();
        for (int i = 0; i <= m; ++i){
            if (k-i>n || k-i<0)
                continue;
            r1 = merge(mm(nums1,i),mm(nums2,k-i));
            if (gg(r1,r,0,0))
                r = r1;
        }
        return r;
    }
};

int main() {
    Solution s;
    return 0;
}
