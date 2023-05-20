class FenwickTree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def update(self, idx, delta):
        while idx <= self.size:
            self.tree[idx] += delta
            idx += idx & -idx

    def query(self, idx):
        result = 0
        while idx > 0:
            result += self.tree[idx]
            idx -= idx & -idx
        return result

class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        N = len(nums)
        BIT = FenwickTree(N)
        
        for i in range(len(nums)):
            BIT.update(i+1, 1)
        
        prevIdx = -1
        sortedNum = sorted([(nums[i], i) for i in range(len(nums))])
        res = 0

        for _, idx in sortedNum:
            if prevIdx == -1:
                res += BIT.query(idx+1)
            elif prevIdx < idx:
                res += BIT.query(idx+1) - BIT.query(prevIdx+1)
            else:
                res += BIT.query(idx + 1) + BIT.query(N) - BIT.query(prevIdx+1)
            
            BIT.update(idx+1, -1)
            prevIdx = idx
        
        return res
    
# much simpler
# https://leetcode.com/problems/make-array-empty/discuss/3466800/JavaC%2B%2BPython-Easy-Sort-Solution
class Solution:
    def countOperationsToEmptyArray(self, nums: List[int]) -> int:
        N = len(nums)
        hmap = {nums[i]:i for i in range(N)}
        res = N
        nums.sort()
        
        for i in range(1, N):
            if hmap[nums[i]] < hmap[nums[i-1]]:
                res += N-i
        
        return res
        