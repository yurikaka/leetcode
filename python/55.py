class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) == 1 :
            return True
        if 0 not in nums :
            return True
        if nums[0] == 0 :
            return False
        nums = nums[::-1]
        found_zero = False
        pos_zero = -1
        for i in range(0,len(nums)) :
            if found_zero :
                if pos_zero == 0 :
                    if i - nums[i] <= pos_zero :
                        found_zero = False
                if i - nums[i] < pos_zero :
                    found_zero = False
                continue
            if nums[i] == 0 :
                found_zero = True
                pos_zero = i
        if found_zero :
            return  False
        return True





s = Solution()
num = [2,0,1,0,1]
print len(num)
print s.canJump(num)
