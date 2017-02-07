class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        result = nums[length-k:length] + nums[:length-k]
        for i in range(length):
            nums[i] = result[i]

s = Solution()
a = [1,2,3,4,5]
s.rotate(a,3)
print a