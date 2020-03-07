class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        n = len(candidates)
        res = []
        def dfs(target,val, start):
            if target<0:
                return
            if target == 0:
                res.append(val) 
            for i in range(start, n):
                if target- candidates[i]<0:
                    break
                dfs(target-candidates[i], val + [candidates[i]], i)
        
        dfs(target, [], 0) 
        return res