class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        jumps = 0
        i = 0
        maxium = []
        while i < len(nums) - 1 :
            if nums[i] + i >= len(nums) - 1 :
                return jumps + 1
            for j in range(1,nums[i]+1) :
                maxium.append(j+nums[i+j])
            i += maxium.index(max(maxium)) + 1
            del maxium[:]
            jumps += 1
        return 0



s = Solution()
num = [2,1]
print s.jump(num)