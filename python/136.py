class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        '''version1: Time Limit Exceeded
        length = len(nums)
        for i in range(0,length - 1):
            found = False
            for j in range(0,length):
                if i != j and nums[i] == nums[j]:
                    found = True
            if not found:
                return nums[i]
        return nums[-1]
        '''

        result = 0
        for i in range(0,len(nums)):
            result ^= nums[i]
        return result

s = Solution()
print s.singleNumber([11,2,3,2,11])