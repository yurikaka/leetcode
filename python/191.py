class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        while n != 0:
            if n%2 == 1:
                result += 1
            n /= 2
        return result

s = Solution()
print s.hammingWeight(11)