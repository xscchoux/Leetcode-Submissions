class Solution(object):
    def equalizeWater(self, buckets, loss):
        """
        :type buckets: List[int]
        :type loss: int
        :rtype: float
        """
        N = len(buckets)
        tot = sum(buckets)
        
        left, right = 0, max(buckets)
        
        def cal(avg):
            demand = 0
            for num in buckets:
                if num > avg:
                    demand += (avg-num)
                elif num < avg:
                    demand += (avg-num)/((100-loss)/float(100))
            return demand
        
        
        while left + 0.00001 < right:
            mid = left + (right-left)/float(2)
            if cal(mid) <= 0:
                left = mid
            else:
                right = mid
                
        return left