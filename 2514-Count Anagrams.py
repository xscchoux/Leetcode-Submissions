class Solution:
    def countAnagrams(self, s: str) -> int:
        kMod = 1000000007
        res = 1
# (a / b) % mod != (a% mod) / (b% mod). So here we use Modular Multiplicative Inverse, i.e (A / B) % mod = A * ( B ^ -1 ) % mod = (A%mod)*(B^-1 %mod)%mod
        
        perm = [1]
        
        for i in range(1, len(s)+1):
            perm.append((perm[-1]*i)%kMod)

        for word in s.split(" "):
            hmap = collections.Counter(word)
            res = res*perm[len(word)]
            for val in hmap.values():
                res = res*pow(perm[val], -1, kMod)
        
        return res%kMod