class Solution(object):
    def kIncreasing(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
# O(NlogN)

        LIStotlen = 0
        
        for start in range(k):
            curr = []
            for i in range(start, len(arr), k):
                if not curr or arr[i] >= curr[-1]:
                    curr.append(arr[i])
                else:
                    idx = bisect.bisect_right(curr, arr[i])
                    curr[idx] = arr[i]
            LIStotlen += len(curr)
        
        return len(arr) - LIStotlen