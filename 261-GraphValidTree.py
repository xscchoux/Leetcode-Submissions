class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
# DFS
# check 
# 1. If there's a cycle in the graph    2. If the graph is not a connected component
        visited = [False]*n
        graph = collections.defaultdict(list)
        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)
        
        def dfs(curr, prev):
            visited[curr] = True
            for nxt in graph[curr]:
                if nxt != prev:
                    if visited[nxt]:
                        return False
                    if not dfs(nxt, curr):
                        return False
            return True
        
        if not dfs(0, -1):
            return False
        
        for i in range(n):
            if not visited[i]:
                return False
            
        return True
    
# BFS
        if len(edges) != n-1:
            return False
        
        graph = collections.defaultdict(list)
        for start, end in edges:
            graph[start].append(end)
            graph[end].append(start)

        queue = collections.deque([])
        queue.append((0, None))
        visited = set()
        visited.add(0)
        
        while queue:
            curr, prev = queue.popleft()
            for nxt in graph[curr]:
                if nxt != prev:
                    if nxt in visited:
                        return False
                    else:
                        visited.add(nxt)
                        queue.append((nxt, curr))
                        
        return len(visited) == n
        
# Union-Find
        if len(edges) != n-1:
            return False
        
        parent = {i:i for i in range(n)}
    
        def find(node):
            if node == parent[node]:
                return node
            else:
                parent[node] = find(parent[node])
                return parent[node]
        
        for u, v in edges:
            parentU, parentV = find(u), find(v)
            if parentU == parentV:
                return False
            parent[parentU] = parentV
        
        return True