class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s1 = ''.join([x for x in s if x.isalpha() or x.isdigit()]).upper()
        return s1 == s1[::-1]

s = Solution()
print s.isPalindrome("0P")