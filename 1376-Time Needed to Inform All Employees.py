class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        child = defaultdict(list)
        t = 0
        
        for i in range(len(manager)):
            if manager[i] != -1:
                child[manager[i]].append(i)
        
        queue = deque([(headID, informTime[headID])])
        
        while queue:
            ID, currT = queue.popleft()
            t = max(currT, t)
            for nxt in child[ID]:
                queue.append((nxt, currT + informTime[nxt]))
        
        return t