# O(N*30*30*30*30), (m<=30 and k <=30)
class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        kMod = pow(10, 9)+7
        N = len(nums)
        @cache
        def dfs(idx, remainM, remainK, carry):
            if remainM < 0 or remainK < 0:
                return 0
            elif remainM == 0 and remainK == carry.bit_count():
                return 1
            
            if idx == N:
                return 0

            res = 0
            for i in range(0, remainM+1):
                ways = ((comb(remainM, i)%kMod)*pow(nums[idx], i, kMod))%kMod
                bits = carry + i
                res = (res + ways*dfs(idx+1, remainM-i, remainK-(bits&1), bits//2))%kMod

            return res

        return dfs(0, m, k, 0)


# O(N*30*30*30*30), add clever pruning
class Solution:
    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        kMod = pow(10, 9)+7
        N = len(nums)
        @cache
        def dfs(idx, remainM, remainK, carry):
            if remainM < 0 or remainK < 0 or remainM + carry.bit_count() < remainK:  # note the pruning technique here
                return 0
            elif remainM == 0 and remainK == carry.bit_count():
                return 1
            
            if idx == N:
                return 0

            res = 0
            for i in range(0, remainM+1):
                ways = ((comb(remainM, i)%kMod)*pow(nums[idx], i, kMod))%kMod
                bits = carry + i
                res = (res + ways*dfs(idx+1, remainM-i, remainK-(bits&1), bits//2))%kMod

            return res

        return dfs(0, m, k, 0)