class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
# DFS TLE
        wordSet = set(wordDict)
        n = len(s)
        res = []
        memo = {}
        def dfs(start, val):
            if start == n:
                res.append(val.strip())
                return
            
            if s[start:] in memo:
                return memo[s[start:]]
            
            for i in range(start, n):
                if s[start:i+1] in wordSet:
                    dfs(i+1, val + " " +s[start:i+1])
                    
        dfs(0, "")
        return res

# DFS + memoization
        memo = {}
        n = len(s)
        wordSet = set(wordDict)
        res = []
        
        def dfs(start):
            if start == n:
                return [""]
            if s[start:] in memo:
                return memo[s[start:]]
            
            partitions = []
            for i in range(start,n):
                if s[start:i+1] in wordSet:
                    subPartitions = dfs(i+1)
                    for partition in subPartitions:
                        partitions.append((s[start:i+1] + " " + partition).strip())
                
            memo[s[start:]] = partitions
            return partitions
        
        return dfs(0)