from collections import deque
class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        deadends = set(deadends)
        
        # edge case
        if "0000" in deadends:
            return -1
        
        queue = deque([("0000", 0)])
        
        def findNext(curr):
            for i in range(len(curr)):
                num = int(curr[i])
                for change in (1, -1):
                    yield curr[:i] + str( (num+change)%10 ) + curr[i+1:]
        
        while queue:
            for _ in range(len(queue)):
                curr, count = queue.popleft()
                if curr == target:
                    return count
                for nxt in findNext(curr):
                    if nxt not in deadends:
                        deadends.add(nxt)
                        queue.append((nxt, count+1))
        return -1