class Solution:
    def powerUpdate(self, nums: list[int], p: int, queries: list[list[int]]) -> list[int]:
        sl = SortedList(nums)
        kMod = 10**9+7
        res = []

        for val, k in queries:
            sl.add(val)
            kth = sl[-k]
            p = pow(p, kth, kMod)
            res.append(p)
        
        return res
