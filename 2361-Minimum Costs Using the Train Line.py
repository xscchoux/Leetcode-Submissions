class Solution(object):
    def minimumCosts(self, regular, express, expressCost):
        """
        :type regular: List[int]
        :type express: List[int]
        :type expressCost: int
        :rtype: List[int]
        """
        N = len(regular)
        
        prev1 = 0
        prev2 = expressCost
        res = []
        
        for i in range(1, N+1):
            curr1 = min(prev1 + regular[i-1], prev2 + express[i-1])
            curr2 = min(prev1 + regular[i-1] + expressCost, prev2 + express[i-1])
            
            prev1, prev2 = curr1, curr2
            res.append(min(curr1, curr2))

        # faster
#         for i in range(1, N+1):
#             prev1 = min(prev1 + regular[i-1], prev2 + express[i-1])
#             prev2 = min(prev1 + expressCost, prev2 + express[i-1])
            
#             res.append(min(prev1, prev2))
            
        return res