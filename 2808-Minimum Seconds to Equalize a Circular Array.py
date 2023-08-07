class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
# https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/discuss/3867950/Maximum-Gap
        hmap = defaultdict(list)
        
        for i, num in enumerate(nums):
            hmap[num].append(i)

        N = len(nums)
        res = N - 1
        
        for v in hmap.values():
            v.append(v[0]+N)
            ans = 0
            for i in range(1, len(v)):
                ans = max(ans, (v[i]-v[i-1])//2 )
            
            res = min(res, ans)
        
        return res