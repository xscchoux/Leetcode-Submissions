class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
# naive recursion solution

        wordSet = set(words)
        words.sort(key = lambda x: -len(x))
        def dfs(word):
            if not word:
                return True
            for i in range(1, len(word)+1):
                if word[:i] in wordSet and (word[i:] in wordSet or dfs(word[i:])):
                    return True
        
        res = []
        
        for word in words:
            wordSet.remove(word)
            for i in range(1, len(word)):
 # adding word[i:] in wordSet makes this code much faster 
                if word[:i] in wordSet and (word[i:] in wordSet or dfs(word[i:])): 
                    res.append(word)
                    break
            wordSet.add(word)       
        return res
                    
    
# DP O(n*k*k)
        words.sort(key = lambda x: -len(x))
        wordSet = set(words)
        
        def dp(word):
            if not wordSet:
                return False
            dp = [0]*(len(word)+1)
            dp[0] = True
            for i in range(1, len(word)+1):
                for j in range(i):
                    if dp[j] is not True:
                        continue
                    if word[j:i] in wordSet:
                        dp[i] = True
                        break
            return dp[-1]
        res = []
        for word in words:
            wordSet.remove(word)
            if dp(word):
                res.append(word)
        return res