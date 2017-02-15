# 168. Excel Sheet Column Title

# Given a positive integer, return its corresponding column title as appear in an Excel sheet.

# For example:

#     1 -> A
#     2 -> B
#     3 -> C
#     ...
#     26 -> Z
#     27 -> AA
#     28 -> AB 

class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        result = ''
        while True:
        	t = n % 26
        	if t == 0:
        		t = 26
        		n -= 26
        	result = chr(t+64) + result
        	if n >= 26:
        		n /= 26
        	else:
        		return result