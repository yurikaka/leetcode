class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        if not heights:
            return 0
        continus = [-1]
        maxium = 0
        continus.append(0)
        heights.append(0)
        for i in range(1,len(heights)):
            if heights[continus[-1]] <= heights[i]:
                continus.append(i)
                continue
            for j in range(0, len(continus) - 1):
                if heights[continus[-1]] > heights[i]:
                    m = continus.pop()
                    n = heights[m] * (i - continus[-1] - 1)
                    if n > maxium:
                        maxium = n
                    continue
                break
            continus.append(i)
        return maxium
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
            return 0
        if not matrix[0]:
            return 0
        n = len(matrix[0])
        m = len(matrix)
        mm = []
        maxium = 0
        increase = 0
        for i in range(0,m):
            mm.append([])
        for i in range(0,n):
            mm[0].append(int(matrix[0][i]))
        maxium = self.largestRectangleArea(mm[0])
        for i in range(1,m):
            for j in range(0,n):
                if int(matrix[i][j]) == 0:
                    mm[i].append(0)
                else:
                    mm[i].append(1 + mm[i-1][j])
            print mm[i]
            x = self.largestRectangleArea(mm[i])
            if x > maxium:
                maxium = x
        return maxium


s = Solution()
m1 = ["11"]
print s.maximalRectangle(m1)