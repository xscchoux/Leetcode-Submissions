class Solution:
    def specialPerm(self, nums: List[int]) -> int:  
# First try, O(N*N*2^N)
        N = len(nums)
        currbits = 0
        kMod = 10**9+7

        @cache
        def dfs(bits, prev):
            if bits == (1<<N)-1:
                return 1
            
            res = 0
            for i in range(N):
                if bits & (1<<i) == 0:
                    if prev is None or prev%nums[i] == 0 or nums[i]%prev == 0:
                        res = ( res + dfs(bits^(1<<i), nums[i]) )%kMod
            return res
            
        ans  = dfs(currbits, None)
        return ans
    
# better, O(N*N*2^N)
        N = len(nums)
        kMod = 10**9+7
        ans = 0
        
        graph = defaultdict(set)
        for i in range(N-1):
            for j in range(i+1, N):
                if nums[i]%nums[j] == 0 or nums[j]%nums[i] == 0:
                    graph[i].add(j)
                    graph[j].add(i)
        
        for i in range(N):
            for j in range(i + 1, N):
                if nums[j] % nums[i] == 0:
                    graph[i].add(j)
                    graph[j].add(i)

        @cache
        def dfs(bits, prevIdx):
            if bits == (1<<N)-1:
                return 1
            
            res = 0
            for i in graph[prevIdx]:
                if bits & (1<<i) == 0:
                    res = ( res + dfs(bits^(1<<i), i) )%kMod
            return res
        
        for i in range(N):
            ans = (ans + dfs(1<<i, i))%kMod
        
        return ans