class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        area = (C-A)*(D-B) + (G-E)*(H-F)
        l = min(C,G) - max(A,E)
        h = min(D,H) - max(B,F)
        if l <= 0 or h <= 0:
            return area
        return area - l*h