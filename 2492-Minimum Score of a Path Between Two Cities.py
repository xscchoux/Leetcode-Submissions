class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        hmap = defaultdict(list)
        for u, v, w in roads:
            hmap[u].append((v, w))
            hmap[v].append((u, w))
            
        used = set([1])
        queue = deque([1])
        res = float('inf')
        
        while queue:
            curr = queue.popleft()
            for nxt, w in hmap[curr]:
                if nxt not in used:
                    used.add(nxt)
                    queue.append(nxt)
                res = min(res, w)
        return res