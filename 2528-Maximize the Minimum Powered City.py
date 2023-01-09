class Solution:
    def maxPower(self, stations: List[int], r: int, k: int) -> int:
        N = len(stations)
        
        def isOK(value, power):
            curr = 0
            toAdd = [0]*N
            
            for i in range(min(r, N)):
                curr += stations[i]
            
            for i in range(N):
                if i + r < N:
                    curr += (stations[i+r] + toAdd[i+r])
                if i - r - 1 >= 0:
                    curr -= (stations[i-r-1] + toAdd[i-r-1])
                if curr >= value:
                    continue
                if value - curr > power:
                    return False
                toAdd[min(N-1, i+r)] += value-curr
                power -= (value-curr)
                curr = value
            return True
        
        
        left, right = 0, sum(stations) + k
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid, k):
                left = mid
            else:
                right = mid
                
        if isOK(right, k):
            return right
        else:
            return left