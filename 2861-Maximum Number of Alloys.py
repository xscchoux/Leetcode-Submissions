class Solution:
    def maxNumberOfAlloys(self, n: int, k: int, budget: int, composition: List[List[int]], stock: List[int], cost: List[int]) -> int:
        left, right = 0, budget + min(stock)
        
        def isOK(mid):
            for i in range(k):
                currCost = 0
                for j in range(n):
                    currCost += max(0, (composition[i][j]*mid-stock[j])*cost[j])
                if currCost <= budget:
                    return True
            return False     
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid
        
        if isOK(right):
            return right
        return left