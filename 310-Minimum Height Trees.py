from collections import defaultdict, deque
class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
# build a graph and use BFS or DFS to obtain the minimum height for each root
# TLE   
#         graph = defaultdict(set)
#         for v1, v2 in edges:
#             graph[v1].add(v2)
#             graph[v2].add(v1)
        
#         def bfs(rootNum, time):
#             queue = deque([rootNum])
#             visited = set()
#             visited.add(rootNum)
#             while queue:
#                 length = len(queue)
#                 time += 1
#                 for _ in range(length):
#                     node = queue.popleft()
#                     for others in graph[node]:
#                         if others not in visited:
#                             visited.add(others)
#                             queue.append(others)    
#             return time
        
#         res = defaultdict(list)
#         _min = float('inf')
#         for i in range(n):
#             tmp = bfs(i, 0)
#             if tmp <= _min:
#                 res[tmp] += [i]
#                 _min = tmp
#         return res[_min]
    
# build a graph and perform BFS from all "leaves"

# edge case: when there are no edges
        if not edges:
            return [0]

        graph = defaultdict(set)
        for v1, v2 in edges:
            graph[v1].add(v2)
            graph[v2].add(v1)
            
        leaves = deque([])
        for key in graph:
            if len(graph[key]) == 1:
                leaves.append(key)
        
        while n > 2:
            leaveNum = len(leaves)
            n -= leaveNum
            for _ in range(leaveNum):
                currLeaf = leaves.popleft()
                for parent in graph[currLeaf]:
                    graph[parent].remove(currLeaf)
                    if len(graph[parent]) == 1:
                        leaves.append(parent)
        return leaves