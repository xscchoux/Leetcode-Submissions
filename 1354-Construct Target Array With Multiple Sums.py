import heapq
class Solution(object):
    def isPossible(self, target):
        """
        :type target: List[int]
        :rtype: bool
        """
        
# first try
        tot = sum(target)
        end = len(target)
        
        while tot != end:
            maxIndex = target.index(max(target))
            rest = tot - target[maxIndex]
            
            if rest == 0 or rest >= target[maxIndex]:
                return False
            
            tmp = target[maxIndex]
            
            if target[maxIndex]%rest == 0:
                target[maxIndex] = rest
            else:
                target[maxIndex] = target[maxIndex] % rest
            tot = tot - tmp + target[maxIndex]
            
        return True

# using heap
        if len(target) == 1:
            return target == [1]
        
        tot = sum(target)
        target = [-num for num in target]
        heapq.heapify(target)
        
        while -target[0] > 1:
            curr = -heapq.heappop(target)
            rest = tot - curr
            
            if rest >= curr or rest == 0 or (curr%rest == 0 and rest != 1):
                return False
            
            tot = rest + curr%rest
            heapq.heappush(target, -(curr%rest))
        return True