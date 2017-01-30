class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            if not s:
                return True
            return False
        if len(p) == 1:
            if len(s) != 1:
                return False
            if p[0] == '.' or p[0] == s[0]:
                return True
            return False
        if p[1] == '*':
            if self.isMatch(s,p[2:]):
                return True
            if not s:
                return False
            if p[0] == '.' or p[0] == s[0]:
                return self.isMatch(s[1:],p)
            return False
        if not s:
            return False
        if p[0] == '.' or p[0] == s[0]:
            return self.isMatch(s[1:],p[1:])
        return False

s = Solution()
print s.isMatch("aaa","a*")