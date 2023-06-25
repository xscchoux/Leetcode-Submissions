class Solution:
    def minimizeConcatenatedLength(self, words: List[str]) -> int:
        N = len(words)
        
        @cache
        def dfs(idx, first, last):
            if idx == N - 1:
                return len(words[idx])
            
            length = len(words[idx])
            nxtFirst = words[idx+1][0]
            nxtLast = words[idx+1][-1]

            return min(length - (last == nxtFirst) + dfs(idx+1, first, nxtLast), length - (first == nxtLast) + dfs(idx+1, nxtFirst, last) )
        
        return dfs(0, words[0][0], words[0][-1])