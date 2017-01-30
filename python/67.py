class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        num = int(a, 2) + int(b, 2)
        bit = []
        if num == 0:
            return '0'
        while True:
            if num == 0:
                break
            num, rem = divmod(num, 2)
            bit.append(str(rem))
        return ''.join(bit[::-1])

s = Solution()
print s.addBinary('11','1')