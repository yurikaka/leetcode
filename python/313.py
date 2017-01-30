class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        '''version1: Time Limit Exceeded
        ugly = set([1])
        for i in range(0,n-1):
            current = min(ugly)
            for j in primes:
                ugly.add(j*current)
            ugly.remove(current)
        return min(ugly)
        '''
        k = len(primes)
        ugly = [4294967296]*n
        ugly[0] = 1
        index = [0]*k
        for i in range(1,n):
            for j in range(0,k):
                ugly[i] = min(ugly[i],ugly[index[j]]*primes[j])
            for j in range(0,k):
                index[j] += ugly[i] == ugly[index[j]]*primes[j]
        return ugly[n-1]


s = Solution()
print s.nthSuperUglyNumber(5,[2,3,5])