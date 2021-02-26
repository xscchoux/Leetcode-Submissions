from collections import Counter
class Solution(object):
    def minSetSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        N = len(arr)
        arrCount = Counter(arr)
        
        count = 0
        size = 0
        
        for val in sorted(arrCount.values(), reverse = True):
            count += val
            size += 1
            if count >= N/float(2):
                return size