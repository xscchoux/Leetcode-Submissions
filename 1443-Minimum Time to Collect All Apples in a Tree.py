class Solution(object):
    def minTime(self, n, edges, hasApple):
        """
        :type n: int
        :type edges: List[List[int]]
        :type hasApple: List[bool]
        :rtype: int
        """
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        visited = set()
        visited.add(0)
        
        def dfs(node):
            has = False
            step = 0
            for nxt in graph[node]:
                if nxt not in visited:
                    visited.add(nxt)
                    newStep, newHas = dfs(nxt)
                    if newHas:
                        step += newStep+2
                    has = has or newHas
            
            if not has:
                has = hasApple[node]
            
            return step, has
        
        return dfs(0)[0]