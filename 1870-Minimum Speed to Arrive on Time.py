class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        left, right = 1, 10**7 # low speed, high speed
        
        def isOK(speed):
            tot = 0
            for x in dist[:-1]:
                tot += (x+speed-1)//speed
            tot += dist[-1]/speed
            return tot <= hour
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                right = mid
            else:
                left = mid

        if isOK(left):
            return left
        elif isOK(right):
            return right
        else:
            return -1
        
        
#The maximum train speed is 10 ^ 7: we may need to finish the last ride in 0.01 hours, and the maximum distance is 10 ^ 5, like this test case:

# [1,1,100000]
# 2.01
# Should return 10**7