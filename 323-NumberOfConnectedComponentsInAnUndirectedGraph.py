from collections import defaultdict, deque
class Solution(object):
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = defaultdict(list)
        visited = set()
        for e1, e2 in edges:
            graph[e1].append(e2)
            graph[e2].append(e1)
        count = 0
        for i in range(n):
            if i not in visited:
                queue = deque([])
                queue.append(i)
                while queue:
                    curr = queue.popleft()
                    for child in graph[curr]:
                        if child not in visited:
                            visited.add(child)
                            queue.append(child)
                count+=1
        return count