from collections import defaultdict
class Solution(object):
    def leadsToDestination(self, n, edges, source, destination):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """
        seen = set()
        graph = defaultdict(set)
        
        for edge in edges:
            graph[edge[0]].add(edge[1])
        
        def dfs(source):
            if len(graph[source]) == 0 and source == destination:
                return True
            if len(graph[source]) == 0 or source == destination:
                return False
            if source in seen:
                return False
            seen.add(source)
            res = True
            for nxt in graph[source]:
                res = res and dfs(nxt)
            seen.remove(source)
            return res
        
        return dfs(source)