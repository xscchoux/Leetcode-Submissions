class TrieNode:
    def __init__(self):
        self.children = dict()
        self.string = ""

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        minCost = defaultdict(lambda: defaultdict(lambda:float('inf')))
        
        keySet = set()
        for c1, c2, cost in zip(original, changed, cost):
            minCost[c1][c2] = min(minCost[c1][c2], cost)
            keySet.add(c1)
            keySet.add(c2)
        
        for k in keySet:
            minCost[k][k] = 0
        
        for k in keySet:
            for i in keySet:
                if minCost[i][k] == float('inf'):   # cannot AC without this line, really HARD!
                    continue
                for j in keySet:
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j])

        # put keys in a trie
        root = TrieNode()
        for key in keySet:
            node = root
            for c in reversed(key):
                if c not in node.children:
                    node.children[c] = TrieNode()
                node = node.children[c]
            node.string = key
        
        N = len(source)
        dp = [float('inf')]*(N+1)
        dp[0] = 0
        
        for i in range(len(source)):
            if source[i] == target[i]:
                dp[i+1] = dp[i]
            node1, node2 = root, root
            for j in range(i, -1, -1):
                if source[j] not in node1.children or target[j] not in node2.children:
                    break
                node1 = node1.children[source[j]]
                node2 = node2.children[target[j]]
                if node1.string and node2.string:
                    dp[i+1] = min(dp[i+1], dp[j] + minCost[node1.string][node2.string])

        return dp[-1] if dp[-1] < float('inf') else -1
