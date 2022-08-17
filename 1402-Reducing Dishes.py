class Solution(object):
    def maxSatisfaction(self, satisfaction):
        """
        :type satisfaction: List[int]
        :rtype: int
        """
# first try
#         satisfaction.sort()
#         ind = 1
#         tot = 0
#         first = -1
#         runningSum = 0
        
#         for i, num in enumerate(satisfaction):
#             if num >= 0:
#                 first = i
#                 break
        
#         if first == -1:
#             return 0
        
#         for i in range(first, len(satisfaction)):
#             tot += ind*satisfaction[i]
#             ind += 1
#             runningSum += satisfaction[i]

#         res = tot
        
#         while first-1 >= 0:
#             tot = tot + runningSum + satisfaction[first-1]
#             res = max(res, tot)
#             runningSum += satisfaction[first-1]
#             first -= 1
            
#         return res


# best solution
        satisfaction.sort()
        used = 0
        res = 0
        
        while satisfaction and satisfaction[-1] + used > 0:
            used += satisfaction.pop()
            res += used
        
        return res