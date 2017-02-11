# 34. Search for a Range

# Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
# For example,
# Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        result = [-1,-1]
        length = len(nums)
        left = 0
        right = length 
        while True:
            if right - left <= 3:
                for i in range(left,right):
                    if nums[i] == target:
                        result[0] = i
                        break
                break
            mid = (left + right) / 2
            if nums[mid] >= target:
                right = mid + 1
                continue
            else:
                left = mid + 1
                continue
        if result[0] == -1:
            return result
        left = -1
        right = length - 1
        while True:
            if right - left <= 3:
                for i in range(right,left,-1):
                    if nums[i] == target:
                        result[1] = i
                        break
                break
            mid = (left + right) / 2
            if nums[mid] > target:
                right = mid - 1
                continue
            else:
                left = mid - 1
                continue
        return result