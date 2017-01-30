class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return 0
        cnt = 1
        upper = int(pow(n,0.5))
        passed = [False]*n
        for i in range(3,n,2):
            if not passed[i]:
                cnt += 1
                if i <= upper:
                    for j in range(i*i,n,i):
                        passed[j] = True
        return cnt

s = Solution()
print s.countPrimes(499979)