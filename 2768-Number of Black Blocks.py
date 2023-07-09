class Solution:
    def countBlackBlocks(self, m: int, n: int, coordinates: List[List[int]]) -> List[int]:
        hmap = defaultdict(int)
        tot = (m-1)*(n-1)
        for r, c in coordinates:
            if r-1 >= 0 and c-1 >= 0:
                hmap[(r-1, c-1)] += 1
            if r+1 < m and c-1 >=0:
                hmap[(r, c-1)] += 1
            if r-1 >= 0 and c+1 < n:
                hmap[(r-1, c)] += 1
            if r+1 < m and c+1 < n:
                hmap[(r, c)] += 1
                
        res = [0]*5
        
        for k, v in hmap.items():
            if v >= 5:
                tot -= 1
                continue
            tot -= 1
            res[v] += 1
        
        res[0] = tot
        
        return res