class Solution(object):
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        """
        :type s: str
        :type maxLetters: int
        :type minSize: int
        :type maxSize: int
        :rtype: int
        """
        hmap = defaultdict(int)
        
        for i in range(minSize, len(s)+1):
            w = s[i-minSize:i]
            if len(set(w)) <= maxLetters:
                hmap[w] += 1
        
        if hmap:
            return max(hmap.values())
        else:
            return 0