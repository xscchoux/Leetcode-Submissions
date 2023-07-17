class TrieNode:
    def __init__(self):
        self.children = dict()
        self.isEnd = False

class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
        
        self.root = TrieNode()
        
        for w in forbidden:
            node = self.root
            for i in range(len(w)-1, -1, -1):
                if w[i] not in node.children:
                    node.children[w[i]] = TrieNode()
                node = node.children[w[i]]
            node.isEnd = True
        
        def checkHas(start, end):
            node = self.root
            for i in range(end, start-1, -1):
                if word[i] not in node.children:
                    return False
                node = node.children[word[i]]
                if node.isEnd:
                    return True
            return False
        
        left = res = 0
        for i in range(len(word)):
            while left <= i and checkHas(left, i):
                left += 1
            res = max(res, i-left+1)
        
        return res
        

class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
# https://leetcode.com/problems/length-of-the-longest-valid-substring/discuss/3771520/Python-HashMap-and-Trie-Solutions
        forbidden = set(forbidden)
        res = 0
        rightBound = len(word)-1
        maxLen = max(len(s) for s in forbidden)
        N = len(word)
        
        for left in range(N-1, -1, -1):
            for right in range(left, min(left+maxLen, rightBound+1)):
                if word[left:right+1] in forbidden:
                    rightBound = right-1
                    break
            res = max(res, rightBound-left+1)
        return res

class Solution:
    def longestValidSubstring(self, word: str, forbidden: List[str]) -> int:
# https://leetcode.com/problems/length-of-the-longest-valid-substring/discuss/3771220/Python3-Space-Optimized-DP-Solution-Clean-and-Concise
# dp[i] denote the longest valid substring that ends at index i
# dp[i] = min(dp[i], dp[i-1] + 1), there may be forbidden strings in word[:i-1+1], so we consider dp[i-1] + 1
        forbidden = set(forbidden)
        res = 0
        N = len(word)
        dp = [i+1 for i in range(N)]
        
        for i in range(N):
            for j in range(10):
                if i-j < 0:
                    break
                substring = word[i-j:i+1]
                if substring in forbidden:
                    dp[i] = j
                    break
            dp[i] = min(dp[i], dp[i-1]+1)
        
        return max(dp)