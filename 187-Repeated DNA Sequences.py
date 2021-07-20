class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
# bit manipulation

        N, L = len(s), 10
        if N <= 10:
            return []
        
        hmap = {"A":0, "C":1, "G":2, "T":3}
        
        bitmask = 0
        res = set()
        visited = set()
        
        for start in range(N-L+1):
            if start == 0:
                for i in range(L):
                    bitmask <<= 2
                    bitmask |= hmap[s[i]]
                visited.add(bitmask)
            else:
                bitmask <<= 2
                bitmask |= hmap[s[start+L-1]]
                bitmask &= ~(3 <<(2*L))
                if bitmask in visited:
                    res.add(s[start:start+L])
                else:
                    visited.add(bitmask)
        return list(res)
    
# Rabin-Karp

        N, L = len(s), 10
        if N <= 10:
            return []
        
        hmap = {"A":0, "C":1, "G":2, "T":3}
        base = 4
    
        currHash = 0
        res = set()
        visited = set()
        
        for start in range(N-L+1):
            if start == 0:
                for i in range(L):
                    currHash = currHash*base + hmap[s[i]]
                visited.add(currHash)
            else:
                currHash = currHash*base - hmap[s[start-1]]*(base**L) + hmap[s[start+L-1]] 
                if currHash in visited:
                    res.add(s[start:start+L])
                else:
                    visited.add(currHash)
        return list(res)