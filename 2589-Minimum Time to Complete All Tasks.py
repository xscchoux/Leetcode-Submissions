# greedy 
class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks.sort(key = lambda x:x[1])
        
        used = [False]*2001
        
        for start, end, duration in tasks:
            count = 0
            for i in range(end, start-1, -1):
                if used[i]:
                    count += 1
            
            ind = end
            while count < duration:
                if not used[ind]:
                    used[ind] = True
                    count += 1
                ind -= 1
        
        res = 0
        for i in range(len(used)):
            if used[i]:
                res += 1
        
        return res
    
    
# Use BIT
class BIT:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n+1)

    def update(self, i, delta):
        while i <= self.n:
            self.bit[i] += delta
            i += i & (-i)

    def query(self, i):
        result = 0
        while i > 0:
            result += self.bit[i]
            i -= i & (-i)
        return result

class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        arr = BIT(2001)
        tasks.sort(key = lambda x:x[1])
        visited = [False]*(2001)
        
        for start, end, duration in tasks:
            count = arr.query(end+1) - arr.query(start)
            if count >= duration:
                continue
            diff = duration - count
            for ind in range(end, start-1, -1):
                if visited[ind]:
                    continue
                arr.update(ind+1, 1)
                visited[ind] = True
                diff -= 1
                if diff == 0:
                    break
        res = 0
        for x in visited:
            if x:
                res += 1
        
        return res