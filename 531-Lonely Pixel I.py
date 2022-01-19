class Solution(object):
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :rtype: int
        """
        row, col = len(picture), len(picture[0])
        
        rowMap = [0]*row
        colMap = [0]*col
        res = 0
        
        for r in range(row):
            for c in range(col):
                if picture[r][c] == "B":
                    rowMap[r] += 1
                    colMap[c] += 1
        
        for r in range(row):
            for c in range(col):
                if picture[r][c] == "B":
                    if rowMap[r] == 1 and colMap[c] == 1:
                        res += 1
        
        return res