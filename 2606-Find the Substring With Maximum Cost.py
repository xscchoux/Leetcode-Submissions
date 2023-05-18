class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        hmap = {c:vals[i] for i, c in enumerate(chars)}
        
        @cache
        def score(char):
            if char not in hmap:
                return ord(s[i]) - ord('a') + 1
            else:
                return hmap[s[i]]   
        
        left = 0
        res = tot = 0
        for i in range(len(s)):
            tot += score(s[i])
            
            while i >= left and tot < 0:
                tot -= score(s[left])
                left += 1
            
            res = max(tot, res)
        
        return res