from sortedcontainers import SortedList
class Solution(object):
    def maximumRobots(self, chargeTimes, runningCosts, budget):
        """
        :type chargeTimes: List[int]
        :type runningCosts: List[int]
        :type budget: int
        :rtype: int
        """
# SortedList, O(nlogn)
        left = 0
        sl = SortedList()
        running = 0
        res = 0
        
        for i in range(len(chargeTimes)):
            running += runningCosts[i]
            sl.add(chargeTimes[i])
            
            while left <= i and sl[-1] + (i-left+1)*running > budget:
                sl.remove(chargeTimes[left])
                running -= runningCosts[left]
                left += 1
            res = max(res, i-left+1)
        
        return res
    
# deque, O(n)
        mx = collections.deque([])
        running = 0
        left = 0
        res = 0
        
        for i in range(len(chargeTimes)):
            running += runningCosts[i]
            
            while mx and chargeTimes[i] > chargeTimes[mx[-1]]:
                mx.pop()
            mx.append(i)
            
            while left <= i and chargeTimes[mx[0]] + running*(i-left+1) > budget:
                running -= runningCosts[left]
                if left == mx[0]:
                    mx.popleft()
                left += 1
                    
            res = max(res, i-left+1)
            
        return res