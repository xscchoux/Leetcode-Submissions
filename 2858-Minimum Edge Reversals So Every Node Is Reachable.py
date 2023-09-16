class Solution:
    def minEdgeReversals(self, n: int, edges: List[List[int]]) -> List[int]:
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append((v, 0))  # next node, cost
            graph[v].append((u, 1))

        def dfs(node, parent):
            tot = 0
            for nxt, cost in graph[node]:
                if nxt == parent:
                    continue
                tot += cost + dfs(nxt, node)
            return tot
        
        dp0 = dfs(0, -1)  # the cost start from node 0
        res = [0]*n
        
        def dfs2(node, parent, preVal):
            res[node] = preVal
            for nxt, cost in graph[node]:
                if nxt == parent:
                    continue
                if cost == 0:
                    dfs2(nxt, node, preVal + 1)
                else:
                    dfs2(nxt, node, preVal - 1)
        
        dfs2(0, -1, dp0)
        
        return res