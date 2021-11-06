class Solution(object):
    def findingUsersActiveMinutes(self, logs, k):
        """
        :type logs: List[List[int]]
        :type k: int
        :rtype: List[int]
        """
        hmap = defaultdict(set)
        for ind, time in logs:
            hmap[ind].add(time)
        
        res = [0]*k
        for key in hmap:
            res[len(hmap[key])-1] += 1
        
        return res