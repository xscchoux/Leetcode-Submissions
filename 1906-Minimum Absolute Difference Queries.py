class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        mx = max(nums)
        N = len(nums)
        m = [0]*(mx+1)
        
        arr = []
        arr.append(m[:])
        res = []
        
        for num in nums:
            m[num] += 1
            arr.append(m[:])

        for s, e in queries:
            tmp = [i for i, (r, l) in enumerate(zip(arr[e+1], arr[s])) if r-l > 0]

            if len(tmp) <= 1:
                res.append(-1)
            else:
                diff = float('inf')
                for st, end in zip(tmp, tmp[1:]):
                    diff = min(diff, end-st)
                res.append(diff)
        
        return res