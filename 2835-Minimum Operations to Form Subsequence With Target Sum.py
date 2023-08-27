class Solution:
    def minOperations(self, nums: List[int], target: int) -> int:
        
# https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/solutions/3965580/Python-3-dollarO(n)dollar-and-Beats-100-in-Time-+-Memory-+-Proof-that-greedy-works./

        if sum(nums) < target:
            return -1
        if sum(nums) == target:
            return 0
        
        hmap = defaultdict(int)
        for num in nums:
            hmap[int(math.log2(num))] += 1

        res = 0
        
        for digit in range(0, 32):
            if target & (1<<digit):
                if hmap[digit]:
                    hmap[digit] -= 1
                    if not hmap[digit]:
                        del hmap[digit]
                else:
                    greater = 30
                    for key in sorted(hmap.keys()):
                        if key > digit:
                            greater = key
                            break
                    res += greater - digit
                    hmap[greater] -= 1
                    for i in range(digit, greater):
                        hmap[i] += 1

            hmap[digit+1] += hmap[digit]//2
        
        return res