class Solution:
    def countGoodSubsequences(self, s: str) -> int:
        kMod = 10**9+7
        tot = 0
        
        arr = [0]*26
        for c in s:
            arr[ord(c)-ord('a')] += 1
            
        mx = max(arr)
        
        fac = [1]*(mx+1)
        ifac = [1]*(mx+1)
        
        for i in range(1, mx+1):
            fac[i] = (i*fac[i-1])%kMod
            ifac[i] = (pow(i, -1, kMod)*ifac[i-1])%kMod
        
        for num in range(1, mx+1):
            subtot = 1
            for count in arr:
                if count >= num:
                    subtot = (subtot*(fac[count]*ifac[num]*ifac[count-num]+1)%kMod )%kMod
            subtot -= 1
            tot = (tot + subtot)%kMod
        
        return tot