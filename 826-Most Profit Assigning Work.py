class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        arr = sorted(zip(difficulty, profit))
        
        worker.sort()
        idx = 0
        maxP = 0
        res = 0
        
        for cap in worker:
            
            while idx < len(arr) and arr[idx][0] <= cap:
                maxP = max(maxP, arr[idx][1])
                idx += 1
            res += maxP
        
        return res