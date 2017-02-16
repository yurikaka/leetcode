# 506. Relative Ranks

# Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

# Example 1:
# Input: [5, 4, 3, 2, 1]
# Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
# Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
# For the left two athletes, you just need to output their relative ranks according to their scores.
# Note:
# N is a positive integer and won't exceed 10,000.
# All the scores of athletes are guaranteed to be unique.

class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if not nums:
        	return None
        sn = sorted(nums,reverse=True)
        result = []
        for i in nums:
        	t = sn.index(i) + 1
        	if t == 1:
        		result.append("Gold Medal")
        	elif t == 2:
        		result.append("Silver Medal")
        	elif t == 3:
        		result.append("Bronze Medal")
        	else:
        		result.append(str(t))
        return result