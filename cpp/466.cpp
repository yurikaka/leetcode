//466. Count The Repetitions
//Define S = [s,n] as the string S which consists of n connected strings s. For example, ["abc", 3] ="abcabcabc".
//
//On the other hand, we define that string s1 can be obtained from string s2 if we can remove some characters from s2 such that it becomes s1. For example, “abc” can be obtained from “abdbec” based on our definition, but it can not be obtained from “acbbe”.
//
//You are given two non-empty strings s1 and s2 (each at most 100 characters long) and two integers 0 ≤ n1 ≤ 106 and 1 ≤ n2 ≤ 106. Now consider the strings S1 and S2, where S1=[s1,n1] and S2=[s2,n2]. Find the maximum integer M such that [S2,M] can be obtained from S1.
//
//Example:
//
//        Input:
//s1="acb", n1=4
//s2="ab", n2=2
//
//Return:
//2


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
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int count[105], nextindex[105];
        memset(count,-1,sizeof(count));
        memset(nextindex,-1,sizeof(nextindex));
        int begin = -1, end, next = 0, cnt = 0;
        count[0] = nextindex[0] = 0;
        for (int i = 1; i <= s2.size(); ++i){
            for (int j = 0; j < s1.size(); ++j){
                if (s1[j] == s2[next]){
                    ++next;
                    if (next == s2.size()){
                        ++cnt;
                        next = 0;
                    }
                }
            }
            for (int j = 0; j < i; ++j)
                if (nextindex[j] == next){
                    begin = j;
                    end = i;
                    break;
                }
            nextindex[i] = next;
            count[i] = cnt;
            if (begin >= 0)
                break;
        }
        if (begin >= n1)
            return count[n1]/n2;
        return ((n1-begin)/(end-begin)*(count[end]-count[begin]) + count[(n1-begin)%(end-begin)+begin])/n2;
    }
};

int main() {
    Solution s;
    return 0;
}
