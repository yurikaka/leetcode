class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        sum  = 0
        for i in range(0,m):
            for j in range(0,n):
                if grid[i][j] == 0:
                    continue
                if i == 0:
                    sum += 1
                elif grid[i-1][j] == 0:
                    sum += 1
                if i == m-1:
                    sum += 1
                elif grid[i+1][j] == 0:
                    sum += 1
                if j == 0:
                    sum += 1
                elif grid[i][j-1] == 0:
                    sum += 1
                if j == n-1:
                    sum += 1
                elif grid[i][j+1] == 0:
                    sum += 1
        return sum

s = Solution()
print s.islandPerimeter([[0,1,0,0], [1,1,1,0], [0,1,0,0], [1,1,0,0]])