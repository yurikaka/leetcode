//565. Array Nesting
//A zero-indexed array A consisting of N different integers is given. The array contains all integers in the range [0, N - 1].
//
//Sets S[K] for 0 <= K < N are defined as follows:
//
//        S[K] = { A[K], A[A[K]], A[A[A[K]]], ... }.
//
//Sets S[K] are finite for each K and should NOT contain duplicates.
//
//Write a function that given an array A consisting of N integers, return the size of the largest set S[K] for this array.
//
//Example 1:
//Input: A = [5,4,0,3,1,6,2]
//Output: 4
//Explanation:
//        A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
//
//One of the longest S[K]:
//S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
//Note:
//        N is an integer within the range [1, 20,000].
//The elements of A are all distinct.
//Each element of array A is an integer within the range [0, N-1].

#include <bits/stdc++.h>

using namespace std;

long long M = 1000000007;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int l = nums.size(), cur , cir, cnt;
        bool found;
        int ans = 0;
        unordered_map<int,int> m;
        int visit[l];
        for (int i = 0; i < l; ++i){
            if (m.count(nums[i]))
                continue;
            found = false;
            cnt = 0;
            memset(visit,0,sizeof(visit));
            cur = nums[i];
            while (!visit[cur]){
                if (m.count(cur)){
                    found = true;
                    m[nums[i]] = cnt + m[cur];
                    ans = max(ans,m[nums[i]]);
                    break;
                }
                ++cnt;
                visit[cur] = 1;
                cur = nums[cur];
            }
            if (found)
                continue;
            ans = max(ans,cnt);
            cir = cur;
            cur = nums[i];
            while (cur != cir){
                m[cur] = cnt--;
                cur = nums[cur];
            }
            m[cir] = cnt;
            cur = nums[cir];
            while (cur != cir){
                m[cur] = cnt;
                cur = nums[cur];
            }
        }
        return ans;
    }
};

int main(){

}