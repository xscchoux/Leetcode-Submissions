class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        n = len(jobs)
        buckets = [0]*k
        self.res = float('inf')
        
        def backtrack(index):
            if index == n:
                self.res = min(self.res, max(buckets))
            else:
                for i in range(k):
                    if buckets[i] + jobs[index] < self.res:
                        buckets[i] += jobs[index]
                        backtrack(index+1)
                        buckets[i] -= jobs[index]
                    if buckets[i] == 0:
                        break
        backtrack(0)
        
        return self.res