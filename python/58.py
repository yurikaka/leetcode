class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.rstrip()
        i = s.rfind(' ')
        l = len(s)
        if i == -1:
            return l
        return l - 1 - i

s = Solution()
print s.lengthOfLastWord("hello world")