class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

# time complexity: O(N*2^N)
        candidates.sort()
        n = len(candidates)
        res = []
        def dfs(start, target, val):
            if target == 0:
                res.append(val)
                return
            for i in range(start,n):
                if target-candidates[i]<0:
                    break
                if i>start and candidates[i] == candidates[i-1]:
                    continue
                dfs(i+1, target-candidates[i], val+[candidates[i]])
        dfs(0, target, [])
        
        return res