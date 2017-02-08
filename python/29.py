class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        flag = (dividend < 0) is (divisor < 0)
        dividend = abs(dividend)
        divisor = abs(divisor)
        result = 0
        while dividend >= divisor:
            i = 1
            temp = divisor
            while dividend >= temp:
                dividend -= temp
                result += i
                temp <<= 1
                i <<= 1
        if not flag:
            result = -result
        return min(max(-2147483648, result), 2147483647)