from heapq import heappush, heappop
class Solution(object):
    def assignTasks(self, servers, tasks):
        """
        :type servers: List[int]
        :type tasks: List[int]
        :rtype: List[int]
        """
        available = []
        using = []
        for ind, val in enumerate(servers):
            heappush(available, (val, ind))
        
        res = []
        time = 0
        idx = 0
        
        while idx < len(tasks):
            time = max(time, idx)
            if not available:
                time = using[0][0]
            while using and using[0][0] <= time:
                popped = heappop(using)
                heappush(available, (popped[1], popped[2]))
                
            used = heappop(available)
            heappush(using, (time+tasks[idx], used[0], used[1]))
            res.append(used[1])
            idx += 1

        return res