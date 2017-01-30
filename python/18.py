class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        length = len(nums)
        if length < 4:
            return []
        nums.sort()
        if nums[length - 1] + nums[length - 2] + nums[length - 3] + nums[length - 4] < target:
            return []
        result = []
        last_i = -999999
        for i in range(0, length - 3):
            if nums[i] == last_i:
                continue
            last_i = nums[i]
            if last_i + nums[i + 1] + nums[i + 2] + nums[i + 3] > target:
                break
            last_j = -999999
            for j in range(i + 1, length - 2):
                if nums[j] == last_j:
                    continue
                last_j = nums[j]
                if last_i + last_j + nums[j + 1] + nums[j + 2] > target:
                    break
                last_m = -999999
                for m in range(j + 1, length - 1):
                    if nums[m] == last_m:
                        continue
                    last_m = nums[m]
                    if last_i + last_j + last_m + nums[m + 1] > target:
                        break
                    last_n = -999999
                    for n in range(m + 1, length):
                        if nums[n] == last_n:
                            continue
                        last_n = nums[n]
                        sum = last_i + last_j + last_m + last_n
                        if sum == target:
                            result.append([last_i, last_j, last_m, last_n])
                            break
                        if sum > target:
                            break
        return result

s = Solution()
print s.fourSum([-474,-445,-442,-426,-410,-382,-369,-367,-356,-351,-339,-335,-335,-320,-318,-313,-276,-250,-227,-215,-209,-209,-200,-198,-189,-183,-154,-149,-138,-134,-121,-110,-97,-93,-86,-66,-61,-54,-33,-12,-9,2,6,13,30,59,82,86,88,111,132,159,162,193,204,220,225,229,231,275,314,327,332,386,400,440,452,457,485],3456)