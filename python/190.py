class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        result = 0
        for i in range(0,32):
            result *= 2
            result += n%2
            n /= 2
        return result

s =Solution()
print s.reverseBits(43261596)