class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        while True:
            if num%5 != 0:
                break
            num /= 5
        while True:
            if num%3 != 0:
                break
            num /= 3
        return not num & (num - 1)

s = Solution()
print s.isUgly(15)