class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
# https://leetcode.com/problems/make-k-subarray-sums-equal/discuss/3366373/k-Cycles
        N = len(arr)
        res = 0
        visited = set()
        
        for i in range(N):
            if i in visited:
                continue
            
            idx = i
            tmp = []
            
            while idx not in visited:
                tmp.append(arr[idx])
                visited.add(idx)
                idx = (idx + k)%N
            
            tmp.sort()
            median = tmp[len(tmp)//2]
            for c in tmp:
                res += abs(c-median)
        
        return res