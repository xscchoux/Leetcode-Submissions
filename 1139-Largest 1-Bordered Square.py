class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        preSumR = [[0] for _ in range(row)]
        preSumC = [[0] for _ in range(col)]
        
        for r in range(row):
            count = 0
            for c in range(col):
                if grid[r][c] == 1:
                    count += 1
                preSumR[r].append(count)

        for c in range(col):
            count = 0
            for r in range(row):
                if grid[r][c] == 1:
                    count += 1
                preSumC[c].append(count)
        
        for side in range(min(row, col), 0, -1):
            for r in range(row-side+1):
                for c in range(col-side+1):
                    if preSumR[r][c+side] - preSumR[r][c] == side and preSumR[r+side-1][c+side] - preSumR[r+side-1][c] == side and preSumC[c][r+side] - preSumC[c][r] == side and preSumC[c+side-1][r+side] - preSumC[c+side-1][r] == side:
                        return side*side
            
        return 0