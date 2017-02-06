class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.append('a')
        i = 0
        while True:
            if nums[i] == 'a':
                break
            if nums[i] == nums[i+1]:
                del nums[i+1]
            else:
                i += 1
        return i


s = Solution()
n1 = [1,1,2]
print s.removeDuplicates(n1)