class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        
# method 1, O( (n-1)! )
        hmap = defaultdict(int)
        for u, v, w in transactions:
            hmap[u] -= w
            hmap[v] += w

        buckets = [v for v in hmap.values() if v]
        
        def dfs(arr):
            if not arr:
                return 0
            
            curr = arr[0]
            
            for i in range(1, len(arr)):
                if curr == -arr[i]:
                    return 1 + dfs(arr[1:i] + arr[i+1:])
            
            res = float('inf')
            for i in range(1, len(arr)):
                if curr*arr[i] < 0:
                    b = arr[i]
                    res = min(res, 1 + dfs(arr[1:i] + arr[i+1:] + [b + curr]))
            
            return res
        
        return dfs(buckets)
        

# method 2, O( (n-1)! )
        hmap = defaultdict(int)
        for u, v, w in transactions:
            hmap[u] -= w
            hmap[v] += w

        buckets = [v for v in hmap.values() if v]
        N = len(buckets)
        self.res = float('inf')

        def dfs(start, count):
            while start < N and buckets[start] == 0:
                start += 1
                
            if start == N:
                if count < self.res:
                    self.res = count
                return
            
            # pruning 1
            if count >= self.res:
                return
            
            curr = buckets[start]
            for i in range(start+1, N):
                if curr*buckets[i] < 0:
                    buckets[i] += curr
                    dfs(start+1, count+1)
                    buckets[i] -= curr
                
                # pruning 2. If curr == -buckets[i], no need to countinue
                if curr + buckets[i] == 0:
                    break
        
        dfs(0, 0)

        return self.res