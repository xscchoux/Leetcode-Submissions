class Solution:
    def countPairs(self, coordinates: List[List[int]], k: int) -> int:
        hmap = defaultdict(int)
        res = 0
        
        for currX, currY in coordinates:
            for x in range(k+1):
                y = k - x
                preX = x^currX
                preY = y^currY
                res += hmap[(preX, preY)]
            hmap[(currX, currY)] += 1
        
        return res