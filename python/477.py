import math

class Solution(object):
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        result = 0
        power = int(math.ceil(math.log(max(nums),2)))
        length = len(nums)
        for i in range(0,power+1):
            zero = 0
            one = 0
            for j in range(0,length):
                if nums[j]%2 == 1:
                    one += 1
                else:
                    zero += 1
                nums[j] /= 2
            result += one*zero
        return result

s = Solution()
n = [4,14,2]
print s.totalHammingDistance(n)