class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        m = 1+int(log2(n))
        self.dp =[[-1]*m for _ in range(n)]

        for i in range(m):
            for j in range(n):
                if i == 0:
                    self.dp[j][0] = parent[j]
                elif self.dp[j][i-1] != -1:
                    self.dp[j][i] = self.dp[ self.dp[j][i-1] ][ i-1 ]        

    def getKthAncestor(self, node: int, k: int) -> int:
        
        while k > 0 and node != -1:
            c = int(log2(k))
            node = self.dp[node][c]
            k -= (1<<c)
        
        return node

# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)