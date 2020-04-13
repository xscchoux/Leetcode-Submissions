from collections import defaultdict
class Solution(object):
    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """
        if not words:
            return []
        
        prefixMap = defaultdict(list)
        for word in words:
            for i in range(len(word)):
                prefixMap[word[:i+1]] += [word]
        
        length = len(words[0])
        res = []
        
        def dfs(ans):
            if len(ans) == length:
                res.append(ans)
                return
            
            prefix = ''
            index = len(ans)
            for w in ans:
                prefix += w[index]
            
            if prefix not in prefixMap:
                return
            else:
                for candidate in prefixMap[prefix]:
                    dfs(ans+[candidate])
                    
        for word in words:
            dfs([word])
            
        return res