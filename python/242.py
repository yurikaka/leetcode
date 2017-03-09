# 242. Valid Anagram
#
# Given two strings s and t, write a function to determine if t is an anagram of s.
#
# For example,
# s = "anagram", t = "nagaram", return true.
# s = "rat", t = "car", return false.
#
# Note:
# You may assume the string contains only lowercase alphabets.
#
# Follow up:
# What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ls = len(s)
        lt = len(t)
        if ls != lt:
            return False
        c = [0]*26
        for i in s:
            c[ord(i)-97] += 1
        for i in t:
            c[ord(i)-97] -= 1
            if c[ord(i)-97] < 0:
                return False
        return True
