//567. Permutation in String My SubmissionsBack To Contest
//        Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
//
//Example 1:
//Input:s1 = "ab" s2 = "eidbaooo"
//Output:True
//Explanation: s2 contains one permutation of s1 ("ba").
//Example 2:
//Input:s1= "ab" s2 = "eidboaoo"
//Output: False
//Note:
//        The input strings only contain lower case letters.
//The length of both given strings is in range [1, 10,000].

#include <std/c++11.h>

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = s1.size(), r = s2.size();
        if (r < l)
            return false;
        vector<int> a(26,0), b(26,0);
        for (auto i : s1){
            a[i-'a']++;
        }
        for (int i = 0; i < l; ++i){
            b[s2[i]-'a']++;
        }
        if (b == a)
            return true;
        for (int i = l; i < r; ++i){
            b[s2[i]-'a']++;
            b[s2[i-l]-'a']--;
            if (b == a)
                return true;
        }
        return false;
    }
};