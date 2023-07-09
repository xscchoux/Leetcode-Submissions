class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        tot = sum( arr[i] for i in range(k-1) )
        res = 0
            
        for i in range(k-1, len(arr)):
            tot += arr[i]
            if tot >= k*threshold:
                res += 1
            tot -= arr[i-k+1]
        
        return res