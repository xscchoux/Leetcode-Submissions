class Solution(object):
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        N = len(graph)
        target = (1<<N)-1
        queue = deque([])
        visited = set()
        
        for i in range(N):
            queue.append((i, 1<<i))
            visited.add((i, 1<<i))
        step = 0

        while queue:
            for i in range(len(queue)):
                node, state = queue.popleft()
                
                if state == target:
                    return step
                
                for nxt in graph[node]:
                    if ((nxt, state|(1<<nxt))) not in visited:
                        visited.add((nxt, state|(1<<nxt)))
                        queue.append((nxt, state|(1<<nxt)))
            step += 1
            
        return step