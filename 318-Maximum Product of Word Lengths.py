class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        code = []
        for word in words:
            code.append(sum(1 << (ord(char) - ord('a')) for char in set(word)))
        res = 0
        for i in range(len(code) - 1):
            for j in range(i+1, len(code)):
                if not (code[i] & code[j]):
                    res = max(res, len(words[i])*len(words[j]))
        return res