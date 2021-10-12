from heapq import heappush, heappop
class Solution(object):
    def minimumXORSum(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
# DP
        N = len(nums1)
        states = (1<<N)-1
        memo = dict()
        
        
        def dfs(idx, bitmask):
            if not bitmask:
                return 0
            if (idx, bitmask) in memo:
                return memo[(idx,bitmask)]
            
            res = float('inf')
            for i in range(N):
                if (bitmask >> i)&1:
                    res = min(res, (nums1[idx]^nums2[i]) + dfs(idx+1, bitmask^(1<<i)))
            
            memo[(idx, bitmask)] = res
            return res
        
        ans = dfs(0, states)
        
        return ans 
    
# Dijkstra's algorithm 
        
        N = len(nums1)
        pq = [(0, (1<<N)-1, 0)]  # cost, bitmask, index of nums1
        visited = set()
        
        while pq:
            cost, bitmask, idx = heappop(pq)
            if bitmask in visited:
                continue
            visited.add(bitmask)
            if not bitmask:
                return cost
            for i in range(N):
                if (bitmask >> i)&1:
                    newMask = bitmask^(1<<i)
                    if newMask not in visited:
                        heappush(pq, (cost + (nums2[i]^nums1[idx]), newMask, idx+1) )

        return -1