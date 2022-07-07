class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        kMod = 1000000007
        @cache
        def dfs(curr, remain):
            res = 0
            if curr == finish:
                res += 1
            for i in range(len(locations)):
                if curr == i:
                    continue
                diff = abs(locations[i]-locations[curr])
                if remain >= diff:
                    res += dfs(i, remain-diff)
            # if abs(locations[curr]-locations[finish]) <= remain:
            #     res += 1
            
            return res%kMod
        
        return dfs(start, fuel)