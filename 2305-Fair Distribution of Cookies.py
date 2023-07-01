class Solution:
    def distributeCookies(self, cookies: List[int], k: int) -> int:
        
        # O(k^N)
        # https://leetcode.com/problems/fair-distribution-of-cookies/discuss/2144299/Python-Backtracking-with-2-prune-beat-100-58ms
        N = len(cookies)
        arr = [0]*N
        self.res = float('inf')
        
        
        def dfs(idx):
            if idx == N:
                self.res = min(self.res, max(arr))
            
            # pruning technique 1
            if max(arr) >= self.res:
                return
            
            for i in range(k):
                arr[i] += cookies[idx]
                dfs(idx+1)
                arr[i] -= cookies[idx]
                
                # pruning technique 2 (very clever), put in empty bags first from left to right
                if not arr[i]:
                    break
            
        dfs(0)
        
        return self.res