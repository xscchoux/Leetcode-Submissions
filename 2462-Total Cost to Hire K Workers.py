from heapq import heappush, heappop
class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        tot = 0
        N = len(costs)
        pq = []

        for i in range(candidates):
            heappush(pq, (costs[i], 0))
        
        for i in range(N-1, max(N-candidates-1, candidates-1), -1):
            heappush(pq, (costs[i], 1))
        
        left, right = candidates-1, N-candidates     
        
        for _ in range(k):
            c, section = heappop(pq)
            tot += c
            if left + 1 < right:
                if section == 0:
                    heappush(pq, (costs[left + 1], 0))
                    left += 1
                else:
                    heappush(pq, (costs[right-1], 1) )
                    right -= 1
        return tot