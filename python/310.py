# 310. Minimum Height Trees

# For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

# Format
# The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

# You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

# Example 1:

# Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

#         0
#         |
#         1
#        / \
#       2   3
# return [1]

# Example 2:

# Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

#      0  1  2
#       \ | /
#         3
#         |
#         4
#         |
#         5
# return [3, 4]
 
# Note:

# (1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”

# (2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

class Solution(object):
	def findMinHeightTrees(self, n, edges):
		"""
		:type n: int
		:type edges: List[List[int]]
		:rtype: List[int]
		"""
		table = {}
		for i in range(n):
			table[i] = [0,[]]
		for i in edges:
			table[i[0]][1].append(i[1])
			table[i[0]][0] += 1
			table[i[1]][1].append(i[0])
			table[i[1]][0] += 1
		leaf = []
		while  len(table) > 2:
			del leaf
			leaf = []
			for i in table.keys():
				if table[i][0] == 1:
					leaf.append(i)
			for i in leaf:
				table[table[i][1][0]][1].remove(i)
				table[table[i][1][0]][0] -= 1
				del table[i]
		result = []
		for i in table:
			result.append(i)
		return result




s = Solution()
print s.findMinHeightTrees(63,[[0,1],[1,2],[0,3],[2,4],[0,5],[4,6],[1,7],[2,8],[3,9],[4,10],[1,11],[3,12],[2,13],[1,14],[8,15],[9,16],[6,17],[8,18],[4,19],[13,20],[19,21],[8,22],[19,23],[23,24],[14,25],[10,26],[3,27],[21,28],[22,29],[6,30],[26,31],[16,32],[15,33],[17,34],[3,35],[14,36],[29,37],[26,38],[34,39],[39,40],[14,41],[20,42],[6,43],[30,44],[9,45],[11,46],[18,47],[3,48],[3,49],[27,50],[12,51],[14,52],[22,53],[30,54],[6,55],[14,56],[12,57],[2,58],[55,59],[24,60],[13,61],[40,62]])
