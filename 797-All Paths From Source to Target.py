from collections import defaultdict
class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        dag = defaultdict(list)
        
        for i in range(len(graph)):
            dag[i] = graph[i]
        
        res = []
        n = len(graph)-1
        
        def dfs(start, path):
            if start == n:
                res.append(path)
                return
            for nxt in graph[start]:
                dfs(nxt, path + [nxt])
        
        dfs(0, [0])
        
        return res