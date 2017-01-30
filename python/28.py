class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        ln = len(needle)
        lh = len(haystack)
        for i in range(0,lh-ln+1):
            if needle == haystack[i:i+ln]:
                return i
        return -1

s = Solution()
print s.strStr("123456","345")