class Solution(object):
    def maximalPathQuality(self, values, edges, maxTime):
        """
        :type values: List[int]
        :type edges: List[List[int]]
        :type maxTime: int
        :rtype: int
        """
# 10 <= time[j], maxTime <= 100
# By this constraint, there are at most 10 nodes in a path.
# O(4**10)
        graph = collections.defaultdict(list)
        
        for u, v, w in edges:
            graph[u].append([v,w])
            graph[v].append([u,w])
        self.res = 0
        
        def dfs(node, visited, value, timeCost):
            if node == 0:
                self.res = max(value, self.res)
            for nxt, time in graph[node]:
                if timeCost + time <= maxTime:
                    if nxt not in visited:
                        dfs(nxt, visited|set([nxt]), value + values[nxt], timeCost+time)
                    else:
                        dfs(nxt, visited, value, timeCost+time)
        
        dfs(0, set([0]), values[0], 0)
        return self.res