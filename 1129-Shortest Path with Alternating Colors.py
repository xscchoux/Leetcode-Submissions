class Solution(object):
    def shortestAlternatingPaths(self, n, red_edges, blue_edges):
        """
        :type n: int
        :type red_edges: List[List[int]]
        :type blue_edges: List[List[int]]
        :rtype: List[int]
        """
        res = [-1]*n
        res[0] = 0
        
        graph = collections.defaultdict(list)
        
        for start, end in red_edges:
            graph[start].append( (end, True) )
            
        for start, end in blue_edges:
            graph[start].append( (end, False) )
            
        queue = collections.deque([(0, None, 0)]) # (node, color, step)
        
        visitedEdge = set()
        
        while queue:
            for _ in range(len(queue)):
                curr, color, step= queue.popleft()
                for nxt, nxtColor in graph[curr]:
                    if nxtColor != color and (nxt, nxtColor) not in visitedEdge:
                        visitedEdge.add((nxt, nxtColor))
                        if res[nxt] == -1:
                            res[nxt] = step+1
                        queue.append((nxt, nxtColor, step+1))   
                
        return res