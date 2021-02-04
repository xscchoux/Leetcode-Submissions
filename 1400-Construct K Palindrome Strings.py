from collections import Counter
class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        if len(s) < k:
            return False
        
        charCount = Counter(s)
        oddCount = 0
        
        for value in charCount.values():
            if value%2 != 0:
                oddCount += 1
        
        return k >= oddCount
        