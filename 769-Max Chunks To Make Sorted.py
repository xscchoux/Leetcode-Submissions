class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        mx = res = 0
        for idx, val in enumerate(arr):
            mx = max(mx, val)
            if idx == mx:
                res += 1
        return res