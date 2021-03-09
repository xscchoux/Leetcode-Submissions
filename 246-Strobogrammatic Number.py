class Solution(object):
    def isStrobogrammatic(self, num):
        """
        :type num: str
        :rtype: bool
        """
        left, right = 0, len(num)-1
        hmap = {"0":"0", "8":"8", "1":"1", "6":"9", "9":"6"}
        
        while left <= right:
            if num[left] not in hmap or hmap[num[left]] != num[right]:
                return False
            else:
                left += 1
                right -= 1

        return True