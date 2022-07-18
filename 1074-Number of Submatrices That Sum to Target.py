class Solution(object):
    def numSubmatrixSumTarget(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: int
        """
        row, col = len(matrix), len(matrix[0])
        preSum = [[0]*(col+1) for _ in range(row+1)]
        
        for r in range(row):
            for c in range(col):
                preSum[r+1][c+1] = matrix[r][c] + preSum[r+1][c] + preSum[r][c+1] - preSum[r][c]
        
        count = 0
        for r1 in range(1, row+1):
            for r2 in range(r1, row+1):
                hmap = collections.defaultdict(int)
                hmap[0] = 1
                
                for c in range(col):
                    currSum = preSum[r2][c+1] - preSum[r1-1][c+1]
                    
                    count += hmap[currSum-target]
                    
                    hmap[currSum] += 1
                    
        return count