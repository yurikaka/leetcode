# 459. Repeated Substring Pattern
#
# Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
#
# Example 1:
# Input: "abab"
#
# Output: True
#
# Explanation: It's the substring "ab" twice.
# Example 2:
# Input: "aba"
#
# Output: False
# Example 3:
# Input: "abcabcabcabc"
#
# Output: True
#
# Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        step = 1
        l = len(s)
        while step < l/2 + 1:
            if l%step != 0:
                step += 1
                continue
            r = True
            for i in xrange(step):
                for j in xrange(1,l/step):
                    if s[i+j*step] != s[i]:
                        r = False
                        break
                if not r:
                    break
            if r:
                return True
            step += 1
        return False