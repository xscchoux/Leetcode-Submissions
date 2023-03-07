class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:   
        def isOK(t):
            tot = 0
            for num in time:
                tot += t//num
            return tot >= totalTrips
        
        mn = min(time)
        left, right = mn, mn*totalTrips
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                right = mid
            else:
                left = mid
        
        if isOK(left):
            return left
        else:
            return right