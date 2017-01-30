class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        way = [1,2]
        for i in range(3,n+1):
            way.append(way[-1]+way[-2])
        return way[-1]
