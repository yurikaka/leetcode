class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if target not in nums:
            return -1
        for i in range(0,len(nums)):
            if target == nums[i]:
                return i