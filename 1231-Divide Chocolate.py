class Solution(object):
    def maximizeSweetness(self, sweetness, k):
        """
        :type sweetness: List[int]
        :type k: int
        :rtype: int
        """
        tot = sum(sweetness)
        left, right = 1, tot//(k+1)
        
        def count(target):
            res = 0
            runningSum = 0
            for i in range(len(sweetness)):
                runningSum += sweetness[i]
                if runningSum >= target:
                    res += 1
                    if res >= k+1:
                        return True
                    runningSum = 0
            return False
        
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if count(mid):
                left = mid
            else:
                right = mid
                
        if count(right):
            return right
        else:
            return left