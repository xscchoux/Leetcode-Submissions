class Solution:
    def minSizeSubarray(self, nums: List[int], target: int) -> int:
        tot = sum(nums)
        q, target = divmod(target, tot)
        if target == 0:
            return q*len(nums)

        arr = nums + nums
        N = len(arr)

        hmap = dict()
        hmap[0] = -1
        curr = 0
        res = float('inf')
        
        for i in range(N):
            curr += arr[i]
            if curr - target in hmap:
                res = min(res, i - hmap[curr-target])
            hmap[curr] = i
        
        return q*len(nums) + res if q*len(nums) + res < float('inf') else -1