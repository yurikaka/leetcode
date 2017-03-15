# 539. Minimum Time Difference My SubmissionsBack To Contest
#
# Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
#
# Example 1:
# Input: ["23:59","00:00"]
# Output: 1
# Note:
# The number of time points in the given list is at least 2 and won't exceed 20000.
# The input time is legal and ranges from 00:00 to 23:59.

class Solution(object):
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        time = []
        for i in timePoints:
            s = i.split(':')
            time.append(int(s[0])*60+int(s[1]))
        time.sort()
        min = 24*60
        for i in xrange(len(time)-1):
            if time[i+1]-time[i] < min:
                min = time[i+1]-time[i]
        if time[0]+24*60 - time[-1] < min:
            min = time[0]+24*60 - time[-1]
        return min