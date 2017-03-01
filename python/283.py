# 283. Move Zeroes
#
# Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#
# For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
#
# Note:
# You must do this in-place without making a copy of the array.
# Minimize the total number of operations.

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        z = -1
        for i in range(l):
            if nums[i] == 0:
                z = i
                break
        if z == -1:
            return
        for i in range(z+1,l):
            if nums[i] != 0:
                nums[z] = nums[i]
                z += 1
                nums[i] = 0
        return