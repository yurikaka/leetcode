class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        '''version1: Time Limit Exceeded
        nums.sort()
        mini = 9999999
        result = 0
        tmp = 0
        length = len(nums)
        last_i = 9999999
        for i in range(0, length - 2):
            if nums[i] - target >= mini or nums[i] == last_i:
                continue
            last_i = nums[i]
            last_j = -99999999
            for j in range(i + 1, length - 1):
                if nums[j] == last_j:
                    continue
                last_j = nums[j]
                last_k = -1
                for k in range(j + 1, length):
                    if nums[k] == last_k:
                        continue
                    last_k = nums[k]
                    tmp = target - (last_i + last_j + last_k)
                    if tmp == 0:
                        return target
                    if 0 <= tmp < mini:
                        mini = target - (last_i + last_j + last_k)
                        result = last_i + last_j + last_k
                        continue
                    if 0 <= -tmp < mini:
                        mini = last_i + last_j + last_k - target
                        result = last_i + last_j + last_k
                        break
                    if -tmp >= mini:
                        break
        return result
        '''
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        length = len(nums)
        last_i = 999999
        for i in range(0,length-2):
            if nums[i] >= target+abs(result) or nums[i] == last_i:
                continue
            last_i = nums[i]
            j = i + 1
            k = length - 1
            while j < k:
                last_j = nums[j]
                last_k = nums[k]
                sum = last_i + last_j + last_k
                if abs(sum-target) < abs(result-target):
                    result = sum
                    if result == target:
                        return target
                if sum > target:
                    while k > 0:
                        k -= 1
                        if nums[k] != last_k:
                            break
                    continue
                while j < length-1:
                    j += 1
                    if nums[j] != last_j:
                        break
        return result


s = Solution()
print s.threeSumClosest([-94,89,-83,-69,-21,-77,-12,-78,-72,-72,-16,-15,75,-77,95,98,-50,-14,42,76,-79,-33,-86,65,-9,97,-11,16,41,-73,-45,21,22,59,86,-93,85,-54,69,28,-20,35,34,16,-77,-9,-92,48,-33,9,-40,-14,-60,95,53,-38,45,4,-90,21,-8,-53,27,45,40,-44,89,3,-94,8,-53,-86,85,-44,44,6,-27,-18,93,14,50,-44,84,18,78,-89,-38,96,98,-62,-36,-25,-94,-17,39,-50,-57,-93,6,-83,-2,48,-78,95,14,48,-91,-12,83,-1,-95,-76,-10,91,10,33,76,85,90,-61,1,-53,-15,-41,-28,86,-59,39,62,84,-34,-17,-64,96,-13,-57,-99,72,-75,77,20,57,56,46,-91,-21,-46,-66,-6,-30,-51,100,-29,-95,83,-38,32,13,90,-37,-54,2,63,77,-63,54,25,-61,23,91,58,40,23,-9,78,92,-37,-98,29,0,-79,37,-73,-92,18,100,-77,-99,58,-12,-87,99,64,-21,-69,16,-41,18,50,7,-57,-10,11,67,-48,-36],185)