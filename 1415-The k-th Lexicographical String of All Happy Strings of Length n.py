class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        hmap = {"1":'a', "2":'b', "3":'c'}
        res = []
        
        def dfs(remain, curr, num):
            if not remain:
                res.append(num)
                return
            for nxt in (1, 2, 3):
                if nxt == curr:
                    continue
                dfs(remain-1, nxt, num*10+nxt)
        
        for i in (1, 2, 3):
            dfs(n-1, i, i)
        
        res.sort()
        if len(res) < k:
            return ""
        
        ans = ""
        for c in str(res[k-1]):
            ans += hmap[c]
        
        return ans