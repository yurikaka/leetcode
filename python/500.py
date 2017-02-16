# 500. Keyboard Row

# Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.


# American keyboard


# Example 1:
# Input: ["Hello", "Alaska", "Dad", "Peace"]
# Output: ["Alaska", "Dad"]
# Note:
# You may use one character in the keyboard more than once.
# You may assume the input string will only contain letters of alphabet.

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []
        for i in words:
        	r = self.row(i.lower()[0])
        	for j in i.lower()[1:]:
        		if self.row(j) != r:
        			r = -1
        			break
        	if r != -1:
        		result.append(i)
        return result

    def row(self,chr):
    	if chr in 'qwertyuiop':
    		return 1
    	elif chr in 'asdfghjkl':
    		return 2
    	else:
    		return 3