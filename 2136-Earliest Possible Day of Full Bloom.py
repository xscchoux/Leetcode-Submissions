class Solution(object):
    def earliestFullBloom(self, plantTime, growTime):
        """
        :type plantTime: List[int]
        :type growTime: List[int]
        :rtype: int
        """
        N = len(plantTime)
        time = [(plantTime[i], growTime[i]) for i in range(N)]

        # sort by growTime in descending order (plant the seed with longest growTime first)
        time.sort(key = lambda x: -x[1])
        
        currPlant = 0
        res = 0
        for i in range(N):
            currPlant += time[i][0]
            res = max(res, currPlant + time[i][1])
            
        return res