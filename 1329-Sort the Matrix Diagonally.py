class Solution(object):
    def diagonalSort(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        hmap = collections.defaultdict(list)
        row, col = len(mat), len(mat[0])
        
        for r in range(row):
            for c in range(col):
                hmap[r-c].append(mat[r][c])
        
        for k in hmap:
            hmap[k].sort(reverse=True)
            
        for r in range(row):
            for c in range(col):
                mat[r][c] = hmap[r-c].pop()
                
        return mat