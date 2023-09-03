class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        
# bottom-up
        N = len(s)
        dp = [0] * (N+1)
        dictionary = set(dictionary)
        
        for i in range(N):
            for j in range(i+1):
                if s[j:i+1] in dictionary:
                    dp[i+1] = max(dp[i+1], dp[j] + (i - j + 1))
                dp[i+1] = max(dp[i+1], dp[i])
        
        return len(s) - dp[-1]
    
# top-down
        dictionary = set(dictionary)
        N = len(s)
        
        @cache
        def dfs(ind):
            if ind < 0:
                return 0
            res = dfs(ind-1)
            for j in range(ind+1):
                if s[j:ind+1] in dictionary:
                    res = max(res, dfs(j-1) + (ind-j+1))
            return res
        
        return len(s) - dfs(N-1)

# bottom-up2 
        dictionary = set(dictionary)
        N = len(s)
        dp = [0]*(N+1)
        
        for start in range(N-1, -1, -1):
            dp[start] = 1 + dp[start+1]
            for end in range(start, N):
                if s[start:end+1] in dictionary:
                    dp[start] = min(dp[end+1], dp[start])
        
        return dp[0]

# DP + Trie
class TrieNode:
    def __init__(self):
        self.children = dict()
        self.isWord = False

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        N = len(s)
        
        def buildTrie():
            root = TrieNode()
            for word in dictionary:
                node = root
                for w in word:
                    if w not in node.children:
                        node.children[w] = TrieNode()
                    node = node.children[w]
                node.isWord = True
            return root
        
        root = buildTrie()
        
        @cache
        def dfs(start):
            if start == N:
                return 0
            
            res = 1 + dfs(start+1)
            node = root
            
            for end in range(start, N):
                if s[end] in node.children:
                    node = node.children[s[end]]
                    if node.isWord:
                        res = min(res, dfs(end+1))
                else:
                    break
            return res
            
        return dfs(0)