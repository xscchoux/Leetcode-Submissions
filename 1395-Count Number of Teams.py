class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
# dp
# time complexity: O(n^2)
# space complexity: O(n)
        n = len(rating)
        lowerthan = [0]*n
        higherthan = [0]*n
        
        res = 0
        for i in range(1, n):
            for j in range(i-1, -1, -1):
                if rating[j] < rating[i]:
                    lowerthan[i] += 1
                    res += lowerthan[j]
                    
                if rating[j] > rating[i]:
                    higherthan[i] += 1
                    res += higherthan[j]
                    
        return res