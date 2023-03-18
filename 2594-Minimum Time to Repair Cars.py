class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        
        left, right = 1, min(ranks)*cars*cars
        
        def isOK(time):
            res = 0
            for num in ranks:
                res += isqrt(time//num)
            return res >= cars
        
        while left + 1 < right:
            mid = left + (right - left)//2
            if isOK(mid):
                right=mid
            else:
                left = mid
                
        if isOK(left):
            return left
        else:
            return right