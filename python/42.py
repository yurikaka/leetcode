class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        lh = 0
        rh = 0
        water = 0
        local = 0
        for i in range(0,len(height)):
            if height[i] < lh:
                local += lh - height[i]
            else:
                lh = height[i]
                water += local
                local = 0
        local = 0
        i = len(height)-1
        while i >= 0:
            if height[i] == lh:
                break
            if height[i] < rh:
                water += rh - height[i]
            else:
                rh = height[i]
            i -= 1
        return water

s = Solution()
print s.trap([0,1,0,2,1,0,1,3,2,1,2,1])