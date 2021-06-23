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

# bitmask solution
class Solution(object):
    def leadsToDestination(self, n, edges, source, destination):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """
        graph = collections.defaultdict(set)
        
        for s, e in edges:
            graph[s].add(e)
            
        def dfs(start, bitmask):
            
            if not graph[start] and start != destination:
                return False
            
            for nxt in graph[start]:
                # if we have reached "nxt" before in this path, return false
                if not bitmask & (1<<nxt):
                    return False
                if not dfs(nxt, bitmask^(1<<nxt)):
                    return False
            
            return True
        
        return dfs(source, (1<<n)-1)
        