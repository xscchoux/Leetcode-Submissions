from heapq import heappush, heappop
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        res = 0
        curr = 0
        pq = []
        
        for a, b in sorted(list(zip(nums1, nums2)), key = lambda x:-x[1]):
            curr += a
            heappush(pq, a)
            if len(pq) > k:
                curr -= heappop(pq)
            if len(pq) == k:
                res = max(res, curr*b)
        
        return res