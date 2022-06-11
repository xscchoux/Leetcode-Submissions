class Solution(object):
    def matchReplacement(self, s, sub, mappings):
        """
        :type s: str
        :type sub: str
        :type mappings: List[List[str]]
        :rtype: bool
        """
    
        hmap = collections.defaultdict(set)
        for u, v in mappings:
            hmap[u].add(v)
        
        l = len(sub)
        for i in range(0, len(s)-l+1): 
            found = True
            for a, b in zip(s[i:i+l], sub):
                if a == b or a in hmap[b]:
                    continue
                else:
                    found = False
                    break
            
            if found:
                return True
            
        return False