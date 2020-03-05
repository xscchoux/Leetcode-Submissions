# Topological sort O(V+E)

# Construct the graph
        indegree = {i:0 for i in range(numCourses)}
        graph = defaultdict(list)
        for i in range(len(prerequisites)):
            first = prerequisites[i][1]
            second = prerequisites[i][0]
            graph[first].append(second)
            indegree[second] += 1

# Put those with indegree = 0 into the queue
        queue = deque([])
        for i in range(numCourses):
            if indegree[i] == 0:
                del indegree[i]
                queue.append(i)
# Start topological sort
        while queue:
            size = len(queue)
            for _ in range(size):
                curr = queue.popleft()
                for childNode in graph[curr]:
                    indegree[childNode] -= 1
                    if indegree[childNode] == 0:
                        del indegree[childNode]        
                        queue.append(childNode)
                        
        if not indegree:
            return True
        else:
            return False