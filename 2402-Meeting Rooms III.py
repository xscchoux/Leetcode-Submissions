from heapq import heappush, heappop
class Solution(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: int
        """
# https://leetcode.com/problems/meeting-rooms-iii/discuss/2527548/Python-Heap-Solution
        res = [0]*(n)
        rooms = [] # no. of available rooms
        for i in range(n):
            heappush(rooms, i)
        
        meetings.sort()
        using = [] # endtime, no. of room
        
        for start, end in meetings:

            while using and using[0][0] <= start:
                _, roomNum = heappop(using)
                heappush(rooms, roomNum)
            
            if not rooms:
                nxtStart, index = heappop(using)
                heappush(using, (nxtStart + end-start, index))
            else:
                index = heappop(rooms)
                heappush(using, (end, index))
            res[index] += 1
        return res.index(max(res))