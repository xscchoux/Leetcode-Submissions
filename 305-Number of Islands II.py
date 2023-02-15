class Solution:
    def numIslands2(self, m: int, n: int, positions: List[List[int]]) -> List[int]:
        parent = collections.defaultdict(int)
        res = []
        self.curr = 0
        
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            px, py = find(x), find(y)
            if px != py:
                self.curr -= 1
                parent[px] = py
        
        for r, c in positions:
            point = n*r+c
            if point in parent:
                res.append(self.curr)
                continue
            parent[point] = point
            self.curr += 1
            for dr, dc in ((1, 0), (0, 1), (0, -1), (-1, 0)):
                nr, nc = r+dr, c+dc
                if 0<=nr<m and 0<=nc<n and nr*n+nc in parent:
                    union(nr*n+nc, point)
            res.append(self.curr)
            
        return res
    