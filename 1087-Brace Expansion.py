class Solution:
    def expand(self, s: str) -> List[str]:
        arr = s.replace("}"," ").replace("{", " ").strip().split(" ")
        toExpand = [sorted(x.split(",")) for x in arr]
        res = []
        
        def dfs(ind, val):
            if ind == len(toExpand):
                res.append(val)
                return
            for c in toExpand[ind]:
                dfs(ind+1, val+c)
        dfs(0, "")
        
        return res