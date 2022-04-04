class Solution(object):
    def distanceToCycle(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        
        cycle = []
        visited = set()
        
        def dfs(curr, par):
            if curr in visited:
                return True, curr
            else:
                visited.add(curr)
                cycle.append(curr)
                for nxt in graph[curr]:
                    if nxt == par:
                        continue
                    found, start = dfs(nxt, curr)
                    if found:
                        return True, start
                cycle.pop()
                return False, None
        _, startNode = dfs(0, -1)
        
        queue = collections.deque(cycle[cycle.index(startNode):])
        res = [0]*n
        used = set(queue)
        step = 0
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                for nxt in graph[curr]:
                    if nxt not in used:
                        used.add(nxt)
                        queue.append(nxt)
                        res[nxt] = step + 1
            step += 1
            
        return res