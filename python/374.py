# 374. Guess Number Higher or Lower

# We are playing the Guess Game. The game is as follows:

# I pick a number from 1 to n. You have to guess which number I picked.

# Every time you guess wrong, I'll tell you whether the number is higher or lower.

# You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

# -1 : My number is lower
#  1 : My number is higher
#  0 : Congrats! You got it!
# Example:
# n = 10, I pick 6.

# Return 6.

# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n + 1
        while True:
        	if right - left < 3:
        		for i in range(left, right):
        			if guess(i) == 0:
        				return i
        	mid = left/2 + right/2
        	res = guess(mid)
        	if res == 0:
        		return mid
        	elif res < 0:
        		right = mid
        		continue
        	else:
        		left = mid + 1
        		continue 

