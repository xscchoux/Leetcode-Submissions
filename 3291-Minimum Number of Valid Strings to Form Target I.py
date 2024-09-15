class TrieNode:
    def __init__(self):
        self.children = dict()

class Solution:
    def minValidStrings(self, words: List[str], target: str) -> int:
        root = TrieNode()

        # insert
        for word in words:
            node = root
            for w in word:
                if w not in node.children:
                    node.children[w] = TrieNode()
                node = node.children[w]
        
        N = len(target)
        memo = [math.inf]*N

        @cache
        def dfs(i):
            if (i == N):
                return 0
            if memo[i] != math.inf:
                return memo[i]
            
            ind = i
            res = float('inf')
            node = root

            while ind < N:
                if target[ind] in node.children:
                    node = node.children[target[ind]]
                    ind+=1
                    res = min(res, 1 + dfs(ind))
                else:
                    break
            memo[i] = res
            return res

        dfs(0)

        if memo[0] < math.inf:
            return memo[0]
        return -1