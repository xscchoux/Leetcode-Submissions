from collections import defaultdict
class Solution(object):
    def criticalConnections(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: List[List[int]]
        """
# Time complexity: O(n)
# Space complexity: O(n)
# tarjan algorithm

        graph = defaultdict(set)
        for u,v in connections:
            graph[u].add(v)
            graph[v].add(u)
            
        jump = [-1]*n
        res = []
        
        def dfs(cur, par, level):
            jump[cur] = level + 1
            for child in graph[cur]:
                if child == par:
                    continue
                elif jump[child] == -1:
                    jump[cur] = min(jump[cur], dfs(child, cur, level+1) )
                else:
                    jump[cur] = min(jump[cur], jump[child])
            
            if cur != 0 and jump[cur] == level + 1:
                res.append([par, cur])
            return jump[cur]
        dfs(0, -1, 0)
        return res