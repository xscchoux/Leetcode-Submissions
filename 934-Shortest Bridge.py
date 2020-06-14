class Solution(object):
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
# DFS + BFS
# Time: O(mn), Space: O(mn)
        row = len(A)
        col = len(A[0])
        visited = set()
        perimeter = set()
        
        def dfs(r, c):
            visited.add((r,c))
            for dr, dc in ((0,1),(1,0),(-1,0),(0,-1)):
                newR = r + dr
                newC = c + dc
                if 0<=newR<row and 0<=newC<col and (newR, newC) not in visited:
                    if A[newR][newC] == 0:
                        perimeter.add((newR, newC))
                    else:
                        dfs(newR, newC)
        
        for r in range(row):
            for c in range(col):
                if perimeter:
                    break
                elif A[r][c] == 1:
                    dfs(r,c)
        
        step = 1
        while True:
            new_perimeter = set()
            for r, c in perimeter:
                for dr, dc in ((0,1),(1,0),(-1,0),(0,-1)):
                    newR = r + dr
                    newC = c + dc
                    if 0<=newR<row and 0<=newC<col and (newR, newC) not in visited:
                        if A[newR][newC] == 1:
                            return step
                        else:
                            new_perimeter.add((newR, newC))
            visited |= new_perimeter
            perimeter = new_perimeter
            step+=1
        