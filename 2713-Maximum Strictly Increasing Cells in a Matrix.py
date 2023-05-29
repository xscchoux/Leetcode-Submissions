class Solution:
    def maxIncreasingCells(self, mat: List[List[int]]) -> int:
        row, col = len(mat), len(mat[0])
        
        rowConnectedNum = [0]*row
        colConnectedNum = [0]*col
        
        hmap = defaultdict(list)
        
        for r in range(row):
            for c in range(col):
                hmap[mat[r][c]].append((r, c))
        
        res = 0
        
        for val in sorted(hmap):
            tmp = {(r, c):0 for r, c in hmap[val]}
            
            for r, c in hmap[val]:
                maxVal = max(rowConnectedNum[r], colConnectedNum[c]) + 1
                tmp[(r, c)] = maxVal
                res = max(res, maxVal)
            
            for r, c in hmap[val]:                
                rowConnectedNum[r] = max(rowConnectedNum[r], tmp[(r, c)])
                colConnectedNum[c] = max(colConnectedNum[c], tmp[(r, c)])
        
        return res