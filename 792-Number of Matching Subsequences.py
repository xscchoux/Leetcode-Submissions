class Solution(object):
    def numMatchingSubseq(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: int
        """
        head = [[] for _ in range(26)]
        for word in words:
            it = iter(word)
            head[ord(next(it))-ord('a')].append(it)
        
        res = 0
        
        for c in s:
            arr = head[ord(c)-ord('a')]
            head[ord(c)-ord('a')] = []
            
            while arr:
                curr = arr.pop()
                nxt = next(curr, None)
                if not nxt:
                    res += 1
                else:
                    head[ord(nxt) - ord('a')].append(curr)
        return res