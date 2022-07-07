class Solution(object):
    def longestPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        hmap = [[0]*26 for _ in range(26)]
        res = 0
        
        for w in words:
            a, b = ord(w[0])-ord('a'), ord(w[1])-ord('a')
            if hmap[b][a]:
                res += 4
                hmap[b][a] -= 1
            else:
                hmap[a][b] += 1
        for i in range(26):
            if hmap[i][i] > 0:
                res += 2
                break         
        return res
