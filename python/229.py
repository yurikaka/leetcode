# 229. Majority Element II

# Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
        	return []
        current1 = nums[0]
        cnt1 = 0
        current2 = nums[0]
        cnt2 = 0
        for i in nums:
        	if i == current1:
        		cnt1 += 1
        	elif i == current2:
        		cnt2 += 1
        	elif cnt1 == 0:
        		current1 = i
        		cnt1 = 1
        	elif cnt2 == 0:
        		current2 = i
        		cnt2 = 1
        	else:
        		cnt1 -= 1
        		cnt2 -= 1
        cnt1,cnt2 = 0,0
        for i in nums:
        	if i == current1:
        		cnt1 += 1
        	elif i == current2:
        		cnt2 += 1
        result = []
        if cnt1 > len(nums)/3:
        	result.append(current1)
        if cnt2 > len(nums)/3:
        	result.append(current2)
        return result
        	