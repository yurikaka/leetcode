class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        c = 0
        for i in range(len(digits)-1,-1,-1):
            digits[i] += 1
            if digits[i] == 10:
                digits[i] = 0
                c = 1
                continue
            c = 0
            break
        if c == 1:
            digits.insert(0,1)
        return digits