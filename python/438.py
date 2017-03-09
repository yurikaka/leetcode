# 438. Find All Anagrams in a String
#
# Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
#
# Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
#
# The order of output does not matter.
#
# Example 1:
#
# Input:
# s: "cbaebabacd" p: "abc"
#
# Output:
# [0, 6]
#
# Explanation:
# The substring with start index = 0 is "cba", which is an anagram of "abc".
# The substring with start index = 6 is "bac", which is an anagram of "abc".
# Example 2:
#
# Input:
# s: "abab" p: "ab"
#
# Output:
# [0, 1, 2]
#
# Explanation:
# The substring with start index = 0 is "ab", which is an anagram of "ab".
# The substring with start index = 1 is "ba", which is an anagram of "ab".
# The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        ls = len(s)
        lp = len(p)
        if lp > ls:
            return []
        m = 0
        l = 0
        c = [0] * 26
        result = []
        for i in p:
            c[ord(i) - 97] += 1
        for i in xrange(ls):
            if c[ord(s[i]) - 97] == 0:
                found = False
                for j in xrange(l, i):
                    if s[j] == s[i]:
                        l = j + 1
                        found = True
                        break
                    m -= 1
                    c[ord(s[j]) - 97] += 1
                if not found:
                    l = i + 1
            else:
                c[ord(s[i]) - 97] -= 1
                m += 1
                if m == lp:
                    result.append(l)
                    c[ord(s[l]) - 97] += 1
                    l += 1
                    m -= 1
            if l > ls - lp:
                return result
        return result

s = Solution()
print s.findAnagrams("abaacbabc","abc")