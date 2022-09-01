class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        
        @cache
        def dp(index):
            
            res = 1
            for direction in (-1, 1):
                for x in range(1, d+1):
                    nxt = index + direction*x
                    if nxt >= len(arr) or nxt < 0:
                        break
                    elif arr[index] <= arr[nxt]:
                        break
                    elif arr[index] > arr[nxt]:
                        res = max(res, 1 + dp(nxt))
            return res
        
        ans = 1
        for i in range(len(arr)):
            ans = max(ans, dp(i))
        
        return ans