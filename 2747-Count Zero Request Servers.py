class Solution:
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key = lambda x:x[1])
        queries = sorted(zip(queries, range(len(queries))))
        hmap = defaultdict(int)
        res = [n]*len(queries)
        left = right = 0
        
        for query, ind in queries:
            while right < len(logs) and logs[right][1] <= query:
                hmap[logs[right][0]] += 1
                right += 1
            
            while left < len(logs) and logs[left][1] < query - x:
                hmap[logs[left][0]] -= 1
                if hmap[logs[left][0]] == 0:
                    del hmap[logs[left][0]]
                left += 1
            
            res[ind] -= len(hmap)
        
        return res