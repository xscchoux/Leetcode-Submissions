class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:

# (n*2^(length of requests))
        N = len(requests)
        res = 0
        
        for state in range(1<<N):
            idx = []
            i = 0

            count = 0
            while state:
                if state & 1:
                    idx.append(i)
                    count += 1
                state = state//2
                i += 1

            if count <= res:
                continue
                
            arr = [0]*n
            for j in idx:
                arr[requests[j][0]] -= 1
                arr[requests[j][1]] += 1
            
            if all(x == 0 for x in arr):
                res = max(res, len(idx))
                
        return res


# (n*2^(length of requests)), pruning
        self.res = 0
        N = len(requests)
        arr = [0]*n
        
        def dfs(idx, count):
            if idx == N:
                if all(x == 0 for x in arr) and count > self.res:
                    self.res = count
                return
            
            # pruning
            if N - idx + count <= self.res:
                return
            
            u, v = requests[idx]
            dfs(idx+1, count)
            
            arr[u] -= 1
            arr[v] += 1
            dfs(idx+1, count+1)
            arr[u] += 1
            arr[v] -= 1
        
        dfs(0, 0)
        return self.res