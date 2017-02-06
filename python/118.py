class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        result = [[1],[1,1]]
        for i in range(2,numRows):
            line = [1]
            for j in range(1,i):
                line.append(result[i-1][j-1]+result[i-1][j])
            line.append(1)
            result.append(line)
        return result
