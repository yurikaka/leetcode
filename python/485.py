class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxium = 0
        current = 0
        length = len(nums)
        for i in range(0,length):
            if nums[i] == 1:
                current += 1
            else:
                if current > maxium:
                    maxium = current
                current = 0
        return current if current > maxium else maxium

s = Solution()
print s.findMaxConsecutiveOnes([1,0,1,1,0,1])