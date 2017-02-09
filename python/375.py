# 375. Guess Number Higher or Lower II

# We are playing the Guess Game. The game is as follows:

# I pick a number from 1 to n. You have to guess which number I picked.

# Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

# However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

# Example:

# n = 10, I pick 8.

# First round:  You guess 5, I tell you that it's higher. You pay $5.
# Second round: You guess 7, I tell you that it's higher. You pay $7.
# Third round:  You guess 9, I tell you that it's lower. You pay $9.

# Game over. 8 is the number I picked.

# You end up paying $5 + $7 + $9 = $21.
# Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

class Solution(object):
    def getMoneyAmount(self, n):
        """
        :type n: int
        :rtype: int
        """
        a = [0]*(n+1)
        passed = []
        for i in range(n+1):
        	passed.append(a[:])
        return self.dp(passed,1,n)
        
    def dp(self,passed,left,right):
    	if left >= right:
    		return 0
    	if passed[left][right] != 0:
    		return passed[left][right]
    	maxium = 2147483647
    	for i in range(left,right+1):
    		temp = i + max(self.dp(passed,left,i-1),self.dp(passed,i+1,right))
    		maxium = min(maxium, temp)
    	passed[left][right] = maxium
    	return maxium

s = Solution()
print s.getMoneyAmount(20)

