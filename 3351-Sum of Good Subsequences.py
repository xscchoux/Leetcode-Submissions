class Solution:
    def sumOfGoodSubsequences(self, nums: List[int]) -> int:
        hmap = defaultdict(lambda:(0, 0))  #  end value: {total, count}
        N = len(nums)
        kMod = 10**9+7

        res = 0
        for i in range(N):
            tot0, cnt0 = hmap[nums[i]]
            tot1, cnt1 = hmap[nums[i]-1]
            tot2, cnt2 = hmap[nums[i]+1]
            currTot = (tot0 + tot1 + tot2 + (nums[i]*(cnt1+cnt2+1))%kMod)%kMod
            hmap[nums[i]] = (currTot, cnt0+cnt1+cnt2 + 1)
            res = (res + currTot-tot0)%kMod

        return res
