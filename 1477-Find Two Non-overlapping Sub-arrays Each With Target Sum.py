class Solution(object):
    def minSumOfLengths(self, arr, target):
        """
        :type arr: List[int]
        :type target: int
        :rtype: int
        """
# sliding window + DP
# dp[i]: minimum length of subarray ending before i that satisfies our criterion
        N = len(arr)
        dp = [float('inf')]*N
        minLen = float('inf')
        tot = 0
        start = 0
        res = float('inf')
        
        for end in range(len(arr)):
            tot += arr[end]
            while tot > target:
                tot-=arr[start]
                start+=1
            if tot == target:
                length = end-start+1
                if start > 0 and dp[start-1] != float('inf'):
                    res = min(res, length + dp[start-1])
                minLen = min(minLen, length)
            dp[end] = minLen
        
        if res == float('inf'):
            return -1
        return res
    
# prefix array and suffix array
# the minimum length of sub-array ends before i and has sum = k

        preHmap = {0: -1}
        prefix = []
        tot = 0
        minLen = float('inf')
        for i in range(len(arr)-1):
            tot += arr[i]
            if tot - target in preHmap:
                minLen = min(minLen, i-preHmap[tot-target])
            preHmap[tot] = i 
            prefix.append(minLen)
        
        sufHmap = {0: len(arr)}
        suffix = []
        tot = 0
        minLen = float('inf')
        for i in range(len(arr)-1, 0, -1):
            tot += arr[i]
            if tot - target in sufHmap:
                minLen = min(minLen, sufHmap[tot-target]-i)
            sufHmap[tot] = i 
            suffix.append(minLen)
        
        res = float('inf')
        N = len(prefix)
        for i in range(N-1):
            res = min(res, prefix[i] + suffix[N-1-i])

        
        return -1 if res == float('inf') else res