from heapq import heappush, heapify
class Solution(object):
    def assignBikes(self, workers, bikes):
        """
        :type workers: List[List[int]]
        :type bikes: List[List[int]]
        :rtype: List[int]
        """
        distance = []
        for i in range(len(workers)):
            distance.append([])
            for j in range(len(bikes)):
                dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1])
                distance[-1].append((dist, i, j))
            distance[-1].sort(reverse = True)
        
        res = [None]*len(workers)
        pq = [x.pop() for x in distance]
        heapify(pq)
        used = set()
        
        while pq:
            _, worker, bike = heappop(pq)
            if bike not in used:
                used.add(bike)
                res[worker] = bike
            else:
                heappush(pq, distance[worker].pop())
        
        return res