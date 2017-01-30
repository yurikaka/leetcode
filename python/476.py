import math

class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        return 2**(int(math.log(num,2)) + 1) - num - 1

s = Solution()
print s.findComplement(5)