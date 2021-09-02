class Solution(object):
    def findLUSlength(self, strs):
        """
        :type strs: List[str]
        :rtype: int
        """
        def isSubsequence(s, t):
            i = j = 0
            while i<len(s) and j < len(t):
                if s[i] == t[j]:
                    i+=1
                j+=1
            if i == len(s):
                return True
            return False
        
        counts = collections.Counter(strs)
        uniqueStr = list(counts.keys())
        uniqueStr.sort(key = len, reverse=True)
        seen = set()
        
        for s in uniqueStr:
            if counts[s] == 1:
                if not any([isSubsequence(s, t) for t in seen]):
                    return len(s)
            else:
                seen.add(s)
                
        return -1