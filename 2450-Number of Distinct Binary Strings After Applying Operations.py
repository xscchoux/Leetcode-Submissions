class Solution:
    def countDistinctStrings(self, s: str, k: int) -> int:
        res = 1
        
        for i in range(k-1, len(s)):
            res = (res*2)%1000000007
            
        return res