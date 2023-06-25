class Solution:
    def countRoutes(self, locations: List[int], start: int, finish: int, fuel: int) -> int:
        kMod = 10**9+7
        
        @cache
        def state(idx, fuel):
            if idx == finish:
                tot = 1
            else:
                tot = 0
            
            for i in range(len(locations)):
                if i == idx:
                    continue
                diff = abs(locations[idx] - locations[i])
                if fuel >= diff:
                    tot = (tot + state(i, fuel - diff))%kMod
            
            return tot
        
        return state(start, fuel)