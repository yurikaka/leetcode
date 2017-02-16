# 213. House Robber II

# Note: This is an extension of House Robber.

# After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

# Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l == 0:
        	return 0
        if l == 1:
        	return nums[0]
        if l == 2:
        	return max(nums[0],nums[1])
        result0 = [-1]*l
        result1 = [-1]*l
        result0[-1] = nums[-1]
        result1[-1] = 0
        result0[-2] = max(nums[-1],nums[-2])
        result1[-2] = nums[-2]
        for i in range(l-3,0,-1):
        	result0[i] = max(result0[i+1],nums[i]+result0[i+2])
        	result1[i] = max(result1[i+1],nums[i]+result1[i+2])
        return max(result0[1],nums[0]+result1[2])