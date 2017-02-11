# 287. Find the Duplicate Number

# Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

# Note:
# You must not modify the array (assume the array is read only).
# You must use only constant, O(1) extra space.
# Your runtime complexity should be less than O(n2).
# There is only one duplicate number in the array, but it could be repeated more than once.

class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 1
        n = len(nums)
        right = n - 1
        while True:
        	if right - left < 3:
        		count = [0,0]
        		for i in range(n):
        			if nums[i] == left:
        				count[0] += 1
        			elif nums[i] == left+1:
        				count[1] += 1
        		if count[0] > 1:
        			return left
        		elif count[1] > 1:
        			return left + 1
        		else:
        			return right
        	count = 0
        	mid = (left+right)/2
        	for i in range(n):
        		if nums[i] <= mid and nums[i] >= left:
        			count += 1
        	if count <= (mid-left+1):
        		left = mid + 1
        		continue
        	else:
        		right = mid 

s = Solution()
print s.findDuplicate([2,5,9,6,9,3,8,9,7,1])