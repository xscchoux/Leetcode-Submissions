class Solution:
    def goodSubsetofBinaryMatrix(self, grid: List[List[int]]) -> List[int]:
        used = defaultdict(int)  # visited bit combination: # of row
        
        for r in range(len(grid)):
            num = sum(v<<i for i, v in enumerate(grid[r]))
            if num == 0:
                return [r]
            for prevBits in used:
                if (num & prevBits) == 0:
                    return [used[prevBits], r]
            used[num] = r
        
        return []