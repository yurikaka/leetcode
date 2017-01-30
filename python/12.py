class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roma = ''
        while num >= 1000:
            roma += 'M'
            num -= 1000
        if num >= 900:
            roma += 'CM'
            num -= 900
        if num >= 500:
            roma += 'D'
            num -= 500
        if num >= 400:
            roma += 'CD'
            num -= 400
        while num >= 100:
            roma += 'C'
            num -= 100
        if num >= 90:
            roma += 'XC'
            num -= 90
        if num >= 50:
            roma += 'L'
            num -= 50
        if num >= 40:
            roma += 'XL'
            num -= 40
        while num >= 10:
            roma += 'X'
            num -= 10
        if num == 9:
            roma += 'IX'
            return roma
        if num >= 5:
            roma += 'V'
            num -= 5
        if num == 4:
            roma += 'IV'
            return roma
        while num > 0:
            roma += 'I'
            num -= 1
        return roma

s = Solution()
print s.intToRoman(3999)