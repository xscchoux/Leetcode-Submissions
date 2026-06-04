class Solution:
    def powerUpdate(self, nums: list[int], p: int, queries: list[list[int]]) -> list[int]:
        res = []
        kMod = 1000000007
        sl = SortedList(nums)
        
        for val, k, in queries:
            sl.add(val)
            kth = sl[len(sl)-k]
            p = pow(p, kth, kMod)
            res.append(p)

        return res