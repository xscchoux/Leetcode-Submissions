class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        nodes = [[0]*26 for _ in range(len(colors))]
        graph = defaultdict(list)
        indegree = [0]*len(colors)
        res = 0
        
        if not edges:
            return 1
        
        for u, v in edges:
            graph[v].append(u)
            indegree[u] += 1
            
        queue = deque([])
        for i in range(len(colors)):
            if indegree[i] == 0:
                queue.append(i)
        
        processed = len(queue)
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                nodes[curr][ord(colors[curr])-97] += 1
                res = max(res, nodes[curr][ord(colors[curr])-97])
                for nxt in graph[curr]:
                    nxt_i = ord(colors[nxt]) - 97
                    for i in range(26):
                        nodes[nxt][i] = max(nodes[curr][i], nodes[nxt][i])
                    indegree[nxt] -= 1
                    if indegree[nxt] == 0:
                        processed += 1
                        queue.append(nxt)
        
        return res if processed == len(colors) else -1