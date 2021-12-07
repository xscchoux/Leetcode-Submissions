class Solution(object):
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        res = []
        for word in words:
            canPut = True
            hmap1 = dict()
            hmap2 = dict()
            for a, b in zip(word, pattern):
                if (a in hmap1 and hmap1[a] != b) or (b in hmap2 and hmap2[b] != a):
                    canPut = False
                    break
                else:
                    hmap1[a] = b
                    hmap2[b] = a
            if canPut:
                res.append(word)
        return res