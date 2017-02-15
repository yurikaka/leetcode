# 169. Majority Element

# Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

# You may assume that the array is non-empty and the majority element always exist in the array.

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt = 1
        current = nums[0]
        for i in nums[1:]:
        	if i == current:
        		cnt += 1
        	else:
        		if cnt == 1:
        			current = i
        		else:
        			cnt -= 1
        return current
