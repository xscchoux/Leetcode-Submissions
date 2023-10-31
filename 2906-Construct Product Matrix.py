class Solution:
    def constructProductMatrix(self, a: List[List[int]]) -> List[List[int]]:
        # Use prefix and suffix product

        row = len(grid)
        col = len(grid[0])
        res = [[1]*col for _ in range(row)]
        kMod = 12345

        product = 1
        for r in range(row):
            for c in range(col):
                res[r][c] = product
                product = product*(grid[r][c]%kMod)%kMod
        
        product = 1
        for r in range(row-1, -1, -1):
            for c in range(col-1, -1, -1):
                res[r][c] = (product*res[r][c])%kMod
                product = product*(grid[r][c]%kMod)%kMod
        
        return res