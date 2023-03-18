from heapq import heappush, heappop
class Solution:
    def findScore(self, nums: List[int]) -> int:
        N = len(nums)
        pq = []
        visited = [False]*N
        for ind, num in enumerate(nums):
            heappush(pq, (num, ind))
        
        res = 0
        while pq:
            val, ind = heappop(pq)
            if not visited[ind]:
                res += val
                visited[ind] = True
                if ind-1 >= 0:
                    visited[ind-1] = True
                if ind + 1 < N:
                    visited[ind+1] = True
        
        return res