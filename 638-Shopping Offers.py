class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        N = len(needs)
        needs = tuple(needs)
        @cache
        def dfs(arr):
            if all(arr[i] == 0 for i in range(N)):
                return 0
            res = float('inf')
            for s in special:
                if all( arr[i] >= s[i] for i in range(N) ):
                    res = min(res, s[-1] + dfs(tuple(arr[i]-s[i] for i in range(N))))
            res = min(res, sum([arr[i]*price[i] for i in range(N)]))
            return res
                    
        return dfs(needs)