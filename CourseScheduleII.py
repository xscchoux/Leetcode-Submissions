from collections import defaultdict, deque
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
# Construct the graph
        indegree = {i:0 for i in range(numCourses)}
        graph = defaultdict(set)
        for i in range(len(prerequisites)):
            start = prerequisites[i][1]
            end = prerequisites[i][0]
            indegree[end] += 1
            graph[start].add(end)
            
# Put items with indegree = 0 into the queue

        queue = deque([])
        for key in range(numCourses):
            if indegree[key] == 0:
                del indegree[key]
                queue.append(key)
                
# Topological sort
        res = []
        while queue:
            size = len(queue)
            for _ in range(size):
                curr = queue.pop()
                res.append(curr)
                for childNode in graph[curr]:
                    indegree[childNode] -= 1
                    if indegree[childNode] == 0:
                        del indegree[childNode]
                        queue.append(childNode)
                        
        if not indegree:
            return res
        else:
            return []