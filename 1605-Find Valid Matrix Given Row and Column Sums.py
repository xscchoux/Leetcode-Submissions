class Solution(object):
    def restoreMatrix(self, rowSum, colSum):
        """
        :type rowSum: List[int]
        :type colSum: List[int]
        :rtype: List[List[int]]
        """
        res = [[0]*len(colSum) for _ in range(len(rowSum))]
        r = c = 0
        while r < len(rowSum) and c < len(colSum):
            if rowSum[r] == colSum[c]:
                res[r][c] = rowSum[r]
                r += 1
                c += 1
            elif rowSum[r] < colSum[c]:
                res[r][c] = rowSum[r]
                colSum[c] -= rowSum[r]
                r += 1
            else:
                res[r][c] = colSum[c]
                rowSum[r] -= colSum[c]
                c += 1
                
        return res