class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ss = []
        length = []
        for i in range(0,len(s)):
            if s[i] in ss :
                length.append(len(ss))
                del ss[:ss.index(s[i])+1]
            ss.append(s[i])
        length.append(len(ss))
        return max(length)


str = "abcabcbb"
s1 = Solution()
print s1.lengthOfLongestSubstring(str)