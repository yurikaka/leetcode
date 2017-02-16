# 198. House Robber

# You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

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
        result = [-1]*l
        result[-1] = nums[-1]
        result[-2] = max(nums[-1],nums[-2])
        for i in range(l-3,-1,-1):
        	result[i] = max(nums[i]+result[i+2],result[i+1])
        return result[0]