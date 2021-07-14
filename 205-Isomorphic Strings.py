class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
# solution 1
        if len(s) != len(t):
            return False
        
        hmap = dict()
        mapped = set()
        
        for i in range(len(s)):
            if s[i] in hmap:
                if t[i] != hmap[s[i]]:
                    return False
            else:
                if t[i] in mapped:
                    return False
                hmap[s[i]] = t[i]
                mapped.add(t[i])
                
        return True
    
# solution 2
        return len(set(s)) == len(set(t)) == len(set(zip(s,t)))