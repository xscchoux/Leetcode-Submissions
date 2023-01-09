class Solution:
    def isItPossible(self, word1: str, word2: str) -> bool:
        hmap1 = collections.Counter(word1)
        hmap2 = collections.Counter(word2)
        
        if abs(len(hmap1) - len(hmap2)) > 2:
            return False
        
        h1 = hmap1.copy()
        h2 = hmap2.copy()        
        
        for k1, v1 in hmap1.items():
            for k2, v2 in hmap2.items():
        
                h1[k1] -= 1
                h2[k2] -= 1
                h1[k2] += 1
                h2[k1] += 1
                
                if h1[k1] == 0:
                    del h1[k1]
                if h2[k2] == 0:
                    del h2[k2]
                
                if len(h1) == len(h2):
                    return True
                
                h1[k1] += 1
                h2[k2] += 1
                h1[k2] -= 1
                h2[k1] -= 1
                
                if h1[k2] == 0:
                    del h1[k2]
                if h2[k1] == 0:
                    del h2[k1]
                
        return False