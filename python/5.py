class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        centre = -1
        width = -1
        max = 0
        double = False
        for i in range(0,len(s)):
            x = 1
            while (i - x >= 0) & (i + x < len(s)):
                if s[i-x] == s[i+x] :
                    x += 1
                else :
                    break
            x -= 1
            if 2 * x + 1 > max :
                max = 2 * x + 1
                centre = i
                width = x
        for i in range(0,len(s)-1):
            if s[i] == s[i+1]:
                x = 1
                while (i - x >= 0) & (i + x + 1 < len(s)):
                    if s[i - x] == s[i + x + 1]:
                        x += 1
                    else:
                        break
                x -= 1
                if 2 * x + 2 > max :
                    max = 2 * x + 2
                    centre = i
                    width = x
                    double = True
        if double :
            return s[centre - width: centre + width + 2]
        return s[centre - width: centre + width + 1]

s = Solution()
s1 = 'acabaccab'
print s.longestPalindrome(s1)