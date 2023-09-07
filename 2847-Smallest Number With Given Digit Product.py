class Solution:
    def smallestNumber(self, n: int) -> str:
        if n == 1:
            return "1"
        
        hmap = defaultdict(int)
        for factor in range(9, 1, -1):
            while n%factor == 0:
                n = n//factor
                hmap[factor] += 1
                
        if n != 1:
            return "-1"
        
        return "".join([str(key)*hmap[key] for key in sorted(hmap.keys())])