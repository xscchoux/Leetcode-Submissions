# Definition for a category handler.
# class CategoryHandler:
#     def haveSameCategory(self, a: int, b: int) -> bool:
#         pass
class Solution:
    def numberOfCategories(self, n: int, categoryHandler: Optional['CategoryHandler']) -> int:
        count = 0
        for i in range(n-1):
            for j in range(i+1, n):
                if categoryHandler.haveSameCategory(i, j):
                    count += 1
                    break
        
        return n - count