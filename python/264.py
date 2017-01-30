class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """

        '''version1: Time Limit Exceeded
        ugly = {1:True}
        i = 0
        while n != 0:
            i += 1
            if ugly.has_key(i):
                ugly[2*i] = True
                ugly[3*i] = True
                ugly[5*i] = True
                n -= 1
        return i
        '''
        ugly = set([1])
        for i in range(0,n-1):
            current = min(ugly)
            ugly.add(2*current)
            ugly.add(3*current)
            ugly.add(5*current)
            ugly.remove(current)
        return min(ugly)

s = Solution()
print s.nthUglyNumber(1000)
