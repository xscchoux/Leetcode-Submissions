from collections import deque
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        arr1 = deque(version1.split("."))
        arr2 = deque(version2.split("."))
        
        while arr1 and arr2:
            int1, int2 = int(arr1.popleft()), int(arr2.popleft())
            if int1 > int2:
                return 1
            elif int2 > int1:
                return -1
        
        while arr1:
            int1 = int(arr1.popleft())
            if int1 > 0:
                return 1
        
        while arr2:
            int2 = int(arr2.popleft())
            if int2 > 0:
                return -1
            
        return 0