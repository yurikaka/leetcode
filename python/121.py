class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        length = len(prices) - 1
        for i in range(0,length):
            prices[i] = prices[i+1] - prices[i]
        max = 0
        sum = 0
        for i in range(0,length):
            sum += prices[i]
            if sum < 0:
                sum = 0
            elif sum > max:
                max = sum
        return max