# 38. Count and Say

# The count-and-say sequence is the sequence of integers beginning as follows:
# 1, 11, 21, 1211, 111221, ...

# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
# Given an integer n, generate the nth sequence.

# Note: The sequence of integers will be represented as a string.

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        last = '1'
        while n > 1:
        	temp = ''
        	cnt = 0
        	last_c = 'a'
        	for i in last:
        		if i != last_c:
        			if last_c != 'a':
	        			temp += str(cnt)
	        			temp += last_c
        			cnt = 1
        			last_c = i
        		else:
        			cnt += 1
        	temp += str(cnt)
	        temp += last_c
	        last = temp
        return last