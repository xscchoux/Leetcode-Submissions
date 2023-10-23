from sortedcontainers import SortedList
class Solution:
    def maxTaskAssign(self, tasks: List[int], workers: List[int], pills: int, strength: int) -> int:
        
    # Using SortedList
        tasks.sort()
        workers.sort()
        
        def isOK(N):
            if N == 0:
                return True
            startIdx = len(tasks) - N
            pillNum = pills
            
            sl = SortedList()
            for i in range(N):
                sl.add(tasks[i])
            
            for i in range(len(workers)-N, len(workers)):
                if workers[i] >= sl[0]:
                    sl.pop(0)
                elif pillNum and workers[i] + strength >= sl[0]:
                    cpillNum -= 1
                    idx = sl.bisect_right(workers[i]+strength)
                    sl.pop(idx-1)
                else:
                    return False
            return True
        
        left, right = 0, min(len(tasks), len(workers))
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid

        if isOK(right):
            return right
        return left


    # Without using SortedList. Hard to come up with (use deque)

        tasks.sort()
        workers.sort()
        
        def isOK(number):
            if number == 0:
                return True
            
            tmpPills = pills
            taskQueue = deque()
            taskIdx = 0
            
            for i in range(len(workers)-number, len(workers)):
                while taskIdx < number and workers[i] + strength >= tasks[taskIdx]:
                    taskQueue.append(tasks[taskIdx])
                    taskIdx += 1
                if not taskQueue:
                    return False
                if workers[i] >= taskQueue[0]:
                    taskQueue.popleft()
                elif tmpPills:
                    tmpPills -= 1
                    taskQueue.pop()
                else:
                    return False
            return True
        
        left, right = 0, min(len(tasks), len(workers))
        
        while left + 1 < right:
            mid = left+(right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid
        
        if isOK(right):
            return right
        return left