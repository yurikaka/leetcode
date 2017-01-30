class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if not digits:
            return []
        map = [[],[],['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z']]
        choice = [0,0,3,3,3,3,3,4,3,4]
        length = len(digits)
        kind = 1
        for i in range(0,length):
            kind *= choice[int(digits[i])]
        result = ['']*kind
        for i in range(0,kind):
            no = i
            for j in range(0,length):
                result[i] += map[int(digits[j])][no%choice[int(digits[j])]]
                no /= choice[int(digits[j])]
        return result

s = Solution()
print s.letterCombinations('23')