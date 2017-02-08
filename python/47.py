class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = [nums[:]]
        length = len(nums)
        while True:
            found = -1
            for i in range(length - 1, 0, -1):
                if nums[i - 1] < nums[i]:
                    found = i - 1
                    break
            if found == -1:
                return result
            found2 = found + 1
            for i in range(found + 2, length):
                if nums[i] > nums[found]:
                    found2 = i
            temp = nums[found]
            nums[found] = nums[found2]
            nums[found2] = temp
            mid = found + 1 + (length - found - 2) / 2
            for i in range(found + 1, mid + 1):
                temp = nums[i]
                nums[i] = nums[found - i]
                nums[found - i] = temp
            result.append(nums[:])