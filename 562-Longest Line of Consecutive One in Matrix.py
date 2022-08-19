class Solution:
    def longestLine(self, mat: List[List[int]]) -> int:
# first try
#         row = len(mat)
#         col = len(mat[0])
#         directions = [(1, 0), (0, 1), (-1, 0), (0, -1), (1, 1), (-1, 1), (-1, -1), (1, -1)]
        
#         @cache
#         def dfs(r, c, direction):
            
#             nr = r + direction[0]
#             nc = c + direction[1]
#             if 0<=nr<row and 0<=nc<col and mat[nr][nc] == 1:
#                 return 1+dfs(nr, nc, direction)
#             else:
#                 return 1
            
#         res = 0
#         for r in range(row):
#             for c in range(col):
#                 if mat[r][c] == 1:
#                     for direc in directions:
#                         nr = r + direc[0]
#                         nc = c + direc[1]
#                         if 0<=nr<row and 0<=nc<col and mat[nr][nc] == 1:
#                             res = max(res, 1+dfs(nr, nc, direc))
#                         else:
#                             res = max(res, 1)
                            
#         return res

        row, col = len(mat), len(mat[0])
        prev = [[0]*4 for _ in range(col)]
        res = 0
        
        for r in range(row):
            curr = []
            for c in range(col):
                if mat[r][c] == 0:
                    curr.append([0]*4)
                    continue
                else:
                    curr.append([1]*4)
                if c > 0:
                    curr[c][0] = curr[c-1][0] + 1
                if r > 0:
                    curr[c][1] = prev[c][1] + 1
                if c < col-1:
                    curr[c][2] = prev[c+1][2] + 1
                if c > 0:
                    curr[c][3] = prev[c-1][3] + 1
                res = max(res, max(curr[c]))
            prev = curr
        
        return res
        