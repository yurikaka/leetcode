class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 0:
            return []
        if n == 1:
            return ['()']
        result = [[''],['()']]
        for i in range(2,n+1):
            result.append([])
            for j in range(0,i):
                for m in range(0,len(result[j])):
                    for k in range(0,len(result[i-j-1])):
                        result[i].append('('+result[j][m]+')'+result[i-j-1][k])
        return result[n]

s = Solution()
print s.generateParenthesis(9)