class Solution(object):
    def palindromePartition(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)

        def changeCount(left, right):
            count = 0
            while left < right:
                if s[left] != s[right]:
                    count += 1
                left+=1
                right-=1
            
            return count
        
        memo = {}
        
        def dfs(start, kLeft):
            
            if (start, kLeft) in memo:
                return memo[(start, kLeft)]
            
            if kLeft == 1:
                return changeCount(start, n-1)
            
            if n-start == kLeft:
                return 0
            
            totalsplit = float('inf')
            
            for split in range(start, n-kLeft+1):
                total = changeCount(start, split) + dfs(split+1, kLeft-1)
                totalsplit = min(total, totalsplit)

            memo[(start, kLeft)] = totalsplit
            return totalsplit
            
        return dfs(0, k)