class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:        
        graph = collections.defaultdict(list)
        # indegree = [0]*n
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            # indegree[u] += 1
            # indegree[v] += 1
            
        res = 0
        
        @cache
        def dfs(node, parent):
            curr = price[node]
            for nxt in graph[node]:
                if nxt == parent:
                    continue
                tmp = dfs(nxt, node)
                curr = max(curr, tmp+price[node])
            return curr
        
        for i in range(n):
            # if indegree[i] > 1:
            #     continue
            tmp = 0
            for nxt in graph[i]:
                tmp = max(tmp, dfs(nxt, i))
            res = max(res, tmp)
        
        return res