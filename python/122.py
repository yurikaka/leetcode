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
        for i in range(0,length):
            if prices[i] > 0:
                sum += prices[i]
        return sum