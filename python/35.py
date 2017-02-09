# Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

# You may assume no duplicates in the array.

# Here are few examples.
# [1,3,5,6], 5 → 2
# [1,3,5,6], 2 → 1
# [1,3,5,6], 7 → 4
# [1,3,5,6], 0 → 0

class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        length =len(nums)
        if length <= 3:
        	for i in range(length):
        		if nums[i] >= target:
        			return i
        	return length
        if nums[length/2] == target:
        	return length/2
        elif nums[length/2] < target:
        	return length/2 + 1 + self.searchInsert(nums[length/2+1:],target)
        else:
        	return self.searchInsert(nums[:length/2],target)

s = Solution()
print s.searchInsert([1,3,5,6],7)