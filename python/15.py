class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        '''version1: Time Limit Exceeded
        passed = []
        passed_line = []
        result = []
        length = len(nums)
        for i in range(0,length-2):
            if nums[i] in passed:
                continue
            for j in range(i+1,length-1):
                if nums[j] in passed or nums[j] in passed_line:
                    continue
                for k in range(j+1,length):
                    if nums[k] in passed or nums[k] in passed_line:
                        continue
                    if nums[i] + nums[j] + nums[k] == 0:
                        result.append([nums[i],nums[j],nums[k]])
                        passed_line.append(nums[j])
                        passed_line.append(nums[k])
            passed.append(nums[i])
            del passed_line[:]
        return result
        '''
        nums.sort()
        result = []
        length = len(nums)
        last_i = 1
        for i in range(0,length-2):
            if nums[i] > 0 or nums[i] == last_i:
                continue
            last_i = nums[i]
            last_j = -99999999
            for j in range(i+1,length-1):
                if nums[j] == last_j:
                    continue
                last_j = nums[j]
                last_k = -1
                for k in range(j+1,length):
                    if nums[k] < 0 or nums[k] == last_k:
                        continue
                    last_k = nums[k]
                    if last_i + last_j + last_k == 0:
                        result.append([last_i,last_j,last_k])
                        break
                    if last_i + last_j + last_k > 0:
                        break
        return result


s = Solution()
print s.threeSum([-14,-3,11,-3,12,-1,11,13,5,6,-11,-14,-6,11,-4,-15,3,-15,9,-10,13,-10,-9,-13,-12,12,-7,12,12,3,9,5,-14,-3,9,13,11,5,3,-6,-12,-1,-5,-3,-4,-2,-10,6,-10,14,3,-11,11,10,-9,7,-1,-9,4,-12,2,-2,8,3,3,-6,-7,-1,6,12,8,9,-12,10,-8,-1,-7,-3,12,-9,-12,1,-5,6,-12,-7,-2,2,-8,-13,5,9,-7,-10,-3,11,-1,-3,-13,-10,-14,11,6,-10,6,13,4,7,-13,-6,13,12,10,-15,4,13,-7,9,-8,0,4,4,-6,12,9,-2,0])