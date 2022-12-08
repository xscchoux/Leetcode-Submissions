class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        # https://www.youtube.com/watch?v=oa26sFeHRNM
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
            
        ind2depth = defaultdict(int)
        
        for i in range(1, n+1):
            smallestIdx = float('inf')
            
            queue = deque([(i, 1)]) # index, depth
            level = [0]*(n+1)
            maxDepth = 0
            level[i] = 1
            
            while queue:
                ind, depth = queue.popleft()
                maxDepth = max(maxDepth, depth)
                smallestIdx = min(smallestIdx, ind)
                for nxt in graph[ind]:
                    if level[nxt] == 0:
                        level[nxt] = depth + 1
                        queue.append((nxt, depth+1))
                    elif level[nxt] == depth:
                        return -1
            ind2depth[smallestIdx] = max(ind2depth[smallestIdx], maxDepth)
        
        return sum(ind2depth.values())