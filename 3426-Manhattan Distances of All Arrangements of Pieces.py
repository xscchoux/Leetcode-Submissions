class Solution:
    def distanceSum(self, m: int, n: int, k: int) -> int:
        kMod = pow(10, 9) + 7
        # combination of other elements when a pair is fixed
        combinations = comb(m*n-2, k-2)%kMod

        res = 0        
        # sum of all vertical distances
        # n*n : pairs of grids in two rows, d: vertical distance, m-d: count of pairs of row with vertical distance d
        
        for d in range(1, m):
            res = (res + n*n*(m-d)*d)%kMod
        
        # sum of all horizontal distances
        # m*m : pairs of grids in two cols, d: horizontal distance, m-d: count of pairs of row with horizontal distance d

        for d in range(1, n):
            res = (res + m*m*(n-d)*d)%kMod

        return res*combinations%kMod