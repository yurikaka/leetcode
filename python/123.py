class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices) - 1
        for i in range(0, length):
            prices[i] = prices[i + 1] - prices[i]
        sum = 0
        max = 0
        left = 0
        _left = 0
        right = -1
        for i in range(0,length):
            if prices[i] < 0:
                if sum > max:
                    max = sum
                    right = i - 1
                    left = _left
            sum += prices[i]
            if sum <= 0:
                sum = 0
                _left = i + 1
        if sum > max:
            max = sum
            left = _left
            right = length - 1
        if max == 0:
            return 0
        max2 = 0
        sum = 0
        for i in range(0,left - 1):
            sum += prices[i]
            if sum < 0:
                sum = 0
            elif sum > max2:
                max2 = sum
        sum = 0
        for i in range(right+1, length):
            sum += prices[i]
            if sum < 0:
                sum = 0
            elif sum > max2:
                max2 = sum
        sum = 0
        max2 = -max2
        for i in range(left,right+1):
            sum += prices[i]
            if sum > 0:
                sum = 0
            elif sum < max2:
                max2 = sum
        return max - max2

s = Solution()
print s.maxProfit([2,1,4])