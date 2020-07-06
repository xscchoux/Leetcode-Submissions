class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """
        row = len(dungeon)
        col = len(dungeon[0])
            
        for i in range(row):
            dungeon[i].append(float('inf'))
            
        dungeon.append([float('inf')]*(col+1))
        
        dungeon[row-1][col] = 1
        dungeon[row][col-1] = 1
        
        for r in range(row-1, -1, -1):
            for c in range(col-1, -1, -1):
                dungeon[r][c] = max(1, min(dungeon[r][c+1], dungeon[r+1][c]) - dungeon[r][c])
        
        return dungeon[0][0]