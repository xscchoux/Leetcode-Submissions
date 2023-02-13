class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        N = len(t)
        M = len(s)
        left = [float('inf')]*len(t)
        right = [float('-inf')]*len(t)
        
        j = 0
        for i in range(N):
            while j < M and t[i] != s[j]:
                j += 1
            if j < M:
                left[i] = j
                j += 1
            else:
                break
        
        j = M-1
        for i in range(N-1, -1, -1):
            while j >= 0 and t[i] != s[j]:
                j -= 1
            if j >= 0:
                right[i] = j
                j -= 1
            else:
                break
        
        def isOK(length):
            if length == N:
                return True
            if right[length] != float('-inf'):
                return True
            if left[N-length-1] != float('inf'):
                return True
            for i in range(N-length-1):
                if left[i] < right[i+length+1]:
                    return True
            return False
            
            
        low, high = 0, len(t)
        while low + 1 < high:
            mid = low + (high-low)//2
            if isOK(mid):
                high = mid
            else:
                low = mid
  
        if isOK(low):
            return low
        else:
            return high