class Solution:
    def longestArithSeqLength(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 2:
            return 2
        
        arrDiff = [defaultdict(lambda: 1) for _ in range(N)]
        res = 2
        
        for i in range(1, N):
            for j in range(i):
                diff = nums[i] - nums[j]
                arrDiff[i][diff] = max(arrDiff[i][diff], arrDiff[j][diff] + 1)
            res = max(res, max(arrDiff[i].values()))
        return res