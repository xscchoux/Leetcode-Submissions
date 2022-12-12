class Solution:
    def countCornerRectangles(self, grid: List[List[int]]) -> int:
        res = 0
        count = collections.defaultdict(int)
        
        for row in grid:
            for ind1, val1 in enumerate(row):
                if val1:
                    for ind2 in range(ind1+1, len(grid[0])):
                        if row[ind2]:
                            res += count[(ind1, ind2)]
                            count[(ind1, ind2)] += 1
        
        return res