class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max = nums[0]
        sum = 0
        for i in range(0,len(nums)):
            sum += nums[i]
            if sum > max:
                max = sum
            if sum < 0:
                sum = 0
        return max

s = Solution()
print s.maxSubArray([-3,-2,0,-1])

