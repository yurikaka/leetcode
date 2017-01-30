class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """

        '''version1
        if num <= 0:
            return False
        while num != 1:
            if num%4 != 0:
                return False
            num /= 4
        return True
        '''

        return num > 0 and (not num&(num-1)) and num%3 == 1

s = Solution()
print s.isPowerOfFour(256)