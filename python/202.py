class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n > 10:
            sum = 0
            while n != 0:
                sum += (n%10)**2
                n /= 10
            n = sum
        if n not in [1,7,10]:
            return False
        return True

s = Solution()
print s.isHappy(11)