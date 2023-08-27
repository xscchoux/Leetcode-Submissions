class Solution:
    def canCross(self, stones: List[int]) -> bool:
        
# Bottom-up
        hmap = defaultdict(set)
        hmap[0].add(0)
         
        for i in range(len(stones)-1):
            if stones[i] in hmap:
                for v in hmap[stones[i]]:
                    for diff in (-1, 0, 1):
                        if v + diff > 0:
                            if stones[i] + v + diff == stones[-1]:
                                return True
                            hmap[stones[i] + v + diff].add(v + diff)
        return False

# DFS + memoization
    
        stoneSet = set(stones)
        
        @cache
        def dfs(stone, prevStep):
            if stone == stones[-1]:
                return True
            
            for diff in (prevStep-1, prevStep, prevStep+1):
                if diff > 0 and stone+diff in stoneSet:
                    if dfs(stone + diff, diff):
                        return True
            return False
    
        return dfs(0, 0)