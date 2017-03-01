# 389. Find the Difference
#
# Given two strings s and t which consist of only lowercase letters.
#
# String t is generated by random shuffling string s and then add one more letter at a random position.
#
# Find the letter that was added in t.
#
# Example:
#
# Input:
# s = "abcd"
# t = "abcde"
#
# Output:
# e
#
# Explanation:
# 'e' is the letter that was added.

class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        cnt = [0]*26
        for i in s:
            cnt[ord(i)-97] += 1
        for i in t:
            cnt[ord(i)-97] -= 1
            if cnt[ord(i)-97] == -1:
                return i