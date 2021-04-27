import heapq
class Solution(object):
    def minAvailableDuration(self, slots1, slots2, duration):
        """
        :type slots1: List[List[int]]
        :type slots2: List[List[int]]
        :type duration: int
        :rtype: List[int]
        """
# Time: O(MlogM + NlogN), Space: O(1)
        ind1 = ind2 = 0
        slots1.sort()
        slots2.sort()      
        
        while ind1 < len(slots1) and ind2 < len(slots2):
            start = max(slots1[ind1][0], slots2[ind2][0])
            end = min(slots1[ind1][1], slots2[ind2][1])
            if end - start >= duration:
                return [start, start+duration]
            if slots2[ind2][1] > slots1[ind1][1]:
                ind1 += 1
            else:
                ind2 += 1
        
        return []
        
        
        
# use heap (hard to come up with)
# Time:O((M+N)log(M+N)), Space:O(M+N)

        queue = filter(lambda x: x[1] - x[0] >= duration, slots1 + slots2)
        heapq.heapify(queue)
        
        while len(queue) > 1:
            curr1 = heapq.heappop(queue)
            curr2 = queue[0]
            start = max(curr1[0], curr2[0])
            end = min(curr1[1], curr2[1])
            if end - start >= duration:
                return [start, start + duration]
        
        return []