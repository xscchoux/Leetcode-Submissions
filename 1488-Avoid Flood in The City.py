from sortedcontainers import SortedList
class Solution(object):
    def avoidFlood(self, rains):
        """
        :type rains: List[int]
        :rtype: List[int]
        """
        hmap = dict()
        res = [-1]*len(rains)
        zeros = SortedList()
        
        for i in range(len(rains)):
            if rains[i] == 0:
                zeros.add(i)
            elif rains[i] not in hmap:
                hmap[rains[i]] = i
            else:
                if not zeros:
                    return []
                pre = hmap[rains[i]]
                zeroIdx = zeros.bisect_left(pre)
                if zeroIdx == len(zeros):
                    return []
                hmap[rains[i]] = i
                res[zeros[zeroIdx]] = rains[i]
                zeros.pop(zeroIdx)
        
        for i in range(len(res)):
            if res[i] == -1 and rains[i] == 0:
                res[i] = 1
        
        return res