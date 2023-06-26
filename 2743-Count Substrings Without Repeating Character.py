class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:    
# First try
        N = len(s)
        left = 0
        bits = 0
        res = 0
        
        for i in range(N):
            num = ord(s[i]) - ord('a')
            while bits & (1<<num) != 0:
                bits = bits^(1<<(ord(s[left]) - ord('a')))
                left += 1
            res += (i-left+1)
            bits = bits^(1<<num)
            
        return res
    
# Better
        N = len(s)
        hmap = defaultdict(int)
        left = 0
        res = 0
        
        for i in range(N):
            if s[i] in hmap and hmap[s[i]] >= left:
                left = hmap[s[i]] + 1
            hmap[s[i]] = i
            res += i-left+1
        
        return res