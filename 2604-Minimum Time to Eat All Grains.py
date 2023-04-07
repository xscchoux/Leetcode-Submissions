class Solution:
    def minimumTime(self, hens: List[int], grains: List[int]) -> int:
        
# sol 1, O(NlogN)
        hens.sort()
        grains.sort()
        N = len(grains)
        
        def isOK(target):
            j = 0 # start index of grains
            leftmost = 0
            for i in range(len(hens)):
                if j == N:
                    return True
                if grains[j] - hens[i] > target:
                    continue
                
                leftmost = hens[i] - grains[j] if hens[i] > grains[j] else 0
                if leftmost > target:
                    return False
                while j < N and hens[i] >= grains[j]:
                    j += 1
                
                while j < N and leftmost*2 + grains[j] - hens[i] <= target:
                    j += 1
                
                while j < N and leftmost + 2*(grains[j] - hens[i]) <= target:
                    j += 1
            
            return j == N
        
        left, right = 0,  2*(max(grains[-1], hens[-1]) - min(grains[0], hens[0]) + 1)
        
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
        
# sol 2 (using bisect, O(N*logN*logN) )

        hens.sort()
        grains.sort()
        N = len(grains)
        
        def isOK(target):
            j = 0 # start index of grains
            for i in range(len(hens)):
                curr = hens[i]
                leftmost = 0
                if curr > grains[j] and curr - grains[j] > target:
                    return False
                if grains[j] - hens[i] > target:
                    continue
                
                if hens[i] > grains[j]:
                    leftmost = hens[i] - grains[j]
                    leftFirst = target-leftmost*2
                    rightFirst = (target-leftmost)//2
                    endPos = curr + max(leftFirst, rightFirst)  
                else:
                    endPos = curr + target
                
                j = bisect_right(grains, endPos)
                
                if j == N:
                    return True
            
            return False
        
        left, right = 0,  2*(max(grains[-1], hens[-1]) - min(grains[0], hens[0]) + 1)
        
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