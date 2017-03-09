# 409. Longest Palindrome
#
# Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
#
# This is case sensitive, for example "Aa" is not considered a palindrome here.
#
# Note:
# Assume the length of given string will not exceed 1,010.
#
# Example:
#
# Input:
# "abccccdd"
#
# Output:
# 7
#
# Explanation:
# One longest palindrome that can be built is "dccaccd", whose length is 7.

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        u = [0]*26
        l = [0]*26
        single = False
        cnt = 0
        for i in s:
            if i.isupper():
                u[ord(i)-65] += 1
            else:
                l[ord(i)-97] += 1
        for i in u:
            cnt += (i/2) * 2
            if i%2 == 1:
                single = True
        for i in l:
            cnt += (i/2) * 2
            if i%2 == 1:
                single = True
        if single:
            cnt += 1
        return cnt