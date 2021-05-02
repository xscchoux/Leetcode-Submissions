import heapq
class Solution(object):
    def carFleet(self, target, position, speed):
        """
        :type target: int
        :type position: List[int]
        :type speed: List[int]
        :rtype: int
        """
# use heap, O(NlogN)
#         queue = []
        
#         for i in range(len(position)):
#             heapq.heappush(queue, [-position[i], speed[i]])
        
#         time = 0
#         res = 0
        
#         while queue:
#             pos, s = heapq.heappop(queue)
#             requiredTime = (target + pos)/float(s)
#             if requiredTime <= time:
#                 continue
#             else:
#                 res += 1
#                 time = requiredTime
        
#         return res
        
    
    
# another way, O(NlogN)
        time = [ (target-p)/float(s) for p, s in sorted(zip(position, speed))]
        
        cur, res = 0, 0
        
        for t in time[::-1]:
            if t <= cur:
                continue
            else:
                res += 1
                cur = t
                
        return res