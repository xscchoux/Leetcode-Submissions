class Solution(object):
    def minimumSemesters(self, n, relations):
        """
        :type n: int
        :type relations: List[List[int]]
        :rtype: int
        """
        graph = collections.defaultdict(list)
        indegree = [0]*n
        for start, end in relations:
            graph[start].append(end)
            indegree[end-1] += 1
        
        queue = deque()
        for i in range(len(indegree)):
            if indegree[i] == 0:
                queue.append(i+1)
                
        if not queue:
            return -1
        
        semester = 1
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                for nxt in graph[curr]:
                    indegree[nxt-1] -= 1
                    if indegree[nxt-1] == 0:
                        queue.append(nxt)
            if not queue:
                break
            else:
                semester+=1
                
        for x in indegree:
            if x != 0:
                return -1
        return semester