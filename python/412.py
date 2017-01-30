class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        s1 = "Fizz"
        s2 = "Buzz"
        s3 = "FizzBuzz"
        result = []
        for i in range(1,n+1):
            if i%5 == 0:
                if i%3 == 0:
                    result.append(s3)
                else:
                    result.append(s2)
            elif i%3 == 0:
                result.append(s1)
            else:
                result.append(str(i))
        return result

s = Solution()
print s.fizzBuzz(15)