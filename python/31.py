class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        found = -1
        for i in range(length-1,0,-1):
            if nums[i-1] < nums[i]:
                found = i - 1
                break
        if found == -1:
            mid = found + 1 + (length - 1) / 2
            for i in range(found + 1, mid + 1):
                temp = nums[i]
                nums[i] = nums[found-i]
                nums[found-i] = temp
            return
        found2 = found + 1
        for i in range(found+2,length):
            if nums[i] > nums[found]:
                found2 = i
        temp = nums[found]
        nums[found] = nums[found2]
        nums[found2] = temp
        mid = found+1+(length-found-2)/2
        for i in range(found+1,mid+1):
            temp = nums[i]
            nums[i] = nums[found-i]
            nums[found-i] = temp