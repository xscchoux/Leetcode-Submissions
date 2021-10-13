class Solution(object):
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """
# BFS
        graph = collections.defaultdict(list)
        for x, y in stones:
            graph[x].append((x, y))
            graph[~y].append((x, y))
        
        visited = set()
        stack = []
        group = 0
        
        for x, y in stones:
            if (x, y) in visited:
                continue
                
            stack.append((x,y))
            visited.add((x,y))
            group += 1
                
            while stack:
                currX, currY = stack.pop()
                for nx, ny in graph[currX]:
                    if (nx, ny) not in visited:
                        visited.add((nx,ny))
                        stack.append((nx, ny))
                for nx, ny in graph[~currY]:
                    if (nx, ny) not in visited:
                        visited.add((nx, ny))
                        stack.append((nx, ny))
            
        return len(stones) - group
        
# brilliant union-find
        parent = dict()
        
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        def union(x, y):
            parent.setdefault(x, x)
            parent.setdefault(y, y)
            
            px, py = find(x), find(y)
            if px != py:
                parent[px] = parent[py]
        
        for x, y in stones:
            union(x, ~y)

        return len(stones) - len(set(find(x) for x in parent))