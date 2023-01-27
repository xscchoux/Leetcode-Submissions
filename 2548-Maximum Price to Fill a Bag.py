class Solution:
    def maxPrice(self, items: List[List[int]], capacity: int) -> float:
        items.sort(key = lambda x: -(x[0]/x[1]))
        
        res = 0
        for price, weight in items:
            if weight <= capacity:
                capacity -= weight
                res += price
            else:
                res += (price*capacity)/weight
                capacity = 0
            if not capacity:
                break
            
        return -1 if capacity else res