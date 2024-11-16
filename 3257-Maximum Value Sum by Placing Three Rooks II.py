# https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-ii/solutions/5651002/python-solution-o-m-n-top-3-in-row-column-top-11-total/
class Solution:
    def maximumValueSum(self, board: List[List[int]]) -> int:
        row, col = len(board), len(board[0])
        largestInCol = [[] for _ in range(col)]  # largest values (at most 3) in each column
        for r, b in enumerate(board):
            h = []
            for c, val in enumerate(b):
                heappush(h, (val, r, c))
                if len(h) > 3:
                    heappop(h)
            while h:
                v, currR, currC = heappop(h)
                heappush(largestInCol[currC], (v, currR, currC))
                if len(largestInCol[currC]) > 3:
                    heappop(largestInCol[currC])
        
        candidates = []
        for data in largestInCol:
            while data:
                val, r, c = heappop(data)
                heappush(candidates, (val, r, c))
                if len(candidates) > 11:
                    heappop(candidates)

        res = float('-inf')
        for x, y, z in combinations(candidates, 3):
            if (x[1] != y[1] and y[1] != z[1] and x[1] != z[1]) and (x[2] != y[2] and y[2] != z[2] and x[2] != z[2]):
                res = max(res, x[0]+y[0]+z[0])

        return res