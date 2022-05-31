class Solution(object):
    def closestNode(self, n, edges, query):
        """
        :type n: int
        :type edges: List[List[int]]
        :type query: List[List[int]]
        :rtype: List[int]
        """
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        def find(start, end, node):
            visited = set()
            def dfs(start, end):
                visited.add(start)
                if start == end:
                    return True
                for nxt in graph[start]:
                    if nxt not in visited:
                        visited.add(nxt)
                        if dfs(nxt, end):
                            return True
                        visited.remove(nxt)
                return False
            
            dfs(start, end)
            # print(visited)
            
            def bfs(node):
                used = set([node])
                queue = collections.deque([node])
                while queue:
                    for _ in range(len(queue)):
                        curr = queue.popleft()
                        if curr in visited:
                            return curr
                        for nxt in graph[curr]:
                            if nxt not in used:
                                used.add(nxt)
                                queue.append(nxt)
                return -1
            
            return bfs(node)
        
        res = []
        for start, end, x in query:
            res.append(find(start, end, x))        
                
        return res