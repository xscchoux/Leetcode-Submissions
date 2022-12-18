class Solution:
    def cycleLengthQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        
        res = []
        
        for u, v in queries:
            count = 1
            while u!=v:
                if u > v:
                    u = u//2
                else:
                    v = v//2
                count += 1
            res.append(count)
        
        return res