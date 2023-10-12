# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        N = mountain_arr.length()
        left, right = 0, N-1
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if mountain_arr.get(mid) < mountain_arr.get(mid+1):
                left = mid
            else:
                right = mid
        
        peak = left
        
        l, r = 0, peak
        
        while l + 1 < r:
            mid = l + (r-l)//2
            if mountain_arr.get(mid) <= target:
                l = mid
            else:
                r = mid
        
        if mountain_arr.get(l) == target:
            return l
        if mountain_arr.get(r) == target:
            return r
        
        
        l, r = peak+1, N-1
        
        while l + 1 < r:
            mid = l + (r-l)//2
            if mountain_arr.get(mid) >= target:
                l = mid
            else:
                r = mid
        
        if mountain_arr.get(l) == target:
            return l
        if mountain_arr.get(r) == target:
            return r
                
        return -1
