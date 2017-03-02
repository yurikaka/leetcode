# 387. First Unique Character in a String
#
# Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
#
# Examples:
#
# s = "leetcode"
# return 0.
#
# s = "loveleetcode",
# return 2.
# Note: You may assume the string contain only lowercase letters.

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return -1
        l = len(s)
        dic = {}
        for i in xrange(l):
            if dic.has_key(s[i]):
                dic[s[i]] += l
            else:
                dic[s[i]] = i
        result = min(dic.items(), key=lambda x: x[1])[1]
        if result < l:
            return result
        return -1
