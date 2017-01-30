class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        r1 = 4294967295
        r2 = 4294967295
        for i in range(0,len(nums)):
            _r1 = r1 ^ (r2 & nums[i])
            _r2 = (nums[i] & r1) ^ (~nums[i] & r2)
            r1 = _r1
            r2 = _r2
        r1 ^= r2
        return r1 if r1 < 2147483648 else r1 - 4294967296

s = Solution()
print s.singleNumber([1,1,-3,1])