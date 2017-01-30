class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height) - 1
        maxium = 0
        while i < j:
            h = min(height[i],height[j])
            maxium = max(maxium,h*(j-i))
            i += height[i] == h
            j -= height[j] == h
        return maxium

s = Solution()
print s.maxArea([1,2,1])