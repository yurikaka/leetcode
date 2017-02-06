class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums1.extend(nums2)
        nums1.sort()
        if len(nums1)%2 == 1 :
            return nums1[len(nums1)/2]
        return (nums1[len(nums1)/2-1] + nums1[len(nums1)/2])/2.0


s = Solution()
n1 = [0,0,0,9,9]
n2 = [0,0,0,0,5,7,7,11,11]
print s.findMedianSortedArrays(n1,n2)

