import heapq
class Solution(object):
    def smallestChair(self, times, targetFriend):
        """
        :type times: List[List[int]]
        :type targetFriend: int
        :rtype: int
        """
        times2 = []
        targetSlot = (times[targetFriend][1], times[targetFriend][0])
        
        for i in range(len(times)):
            times2.append((times[i][1], times[i][0]))
        
        times2.sort(key = lambda x:x[1])
        occupied = []
        vacantNo = []
        for i in range(len(times)):
            heappush(vacantNo, i)
        
        for time in times2:
            while occupied and time[1] >= occupied[0][0]:
                popped = heappop(occupied)
                heappush(vacantNo, popped[2])
            currVacant = heappop(vacantNo)
            if time == targetSlot:
                return currVacant
            heappush(occupied, (time[0], time[1], currVacant))