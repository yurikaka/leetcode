# 401. Binary Watch
#
# A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
#
# Each LED represents a zero or one, with the least significant bit on the right.
#
#
# For example, the above binary watch reads "3:25".
#
# Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
#
# Example:
#
# Input: n = 1
# Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
# Note:
# The order of output does not matter.
# The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
# The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".


class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        result = []
        minute = [['00'],
                  ['01', '02', '04', '08', '16', '32'],
                  ['03', '05', '09', '17', '33', '06', '10', '18', '34', '12', '20', '36', '24', '40', '48'],
                  ['07', '11', '19', '35', '13', '21', '37', '25', '41', '49', '14', '22', '38', '26', '42', '50','28','44','56','52'],
                  ['15', '23', '39', '27', '43', '51', '29', '45', '53', '57', '30', '46', '54', '58'],
                  ['59', '55', '47', '31']]
        hour = [['0'],
                ['1', '2', '4', '8'],
                ['3', '5', '9', '6', '10'],
                ['11', '7']]
        up = min(4, num + 1)
        for i in xrange(up):
            if num - i > 5:
                continue
            for m in hour[i]:
                for n in minute[num - i]:
                    result.append(m + ':' + n)
        return result