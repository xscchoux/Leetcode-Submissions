class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """

# time complexity: O(k*C(9,3))
        res = []
        def dfs(k,val,start,_sum):
            if k == 0 and _sum == n:
                res.append(val)
                return
            for i in range(start,10):
                if n-_sum < i:
                    break
                dfs(k-1, val+[i], i+1, _sum+i)
        dfs(k,[], 1, 0)
        return res