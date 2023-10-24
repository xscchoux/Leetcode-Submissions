class Solution:
    def minGroupsForValidAssignment(self, nums: List[int]) -> int:
        # Time complexity: (count of the least frequent number)*(distinct numbers) <= O(n)
        
        counter = Counter(nums)
        num = float('inf')
        
        for k, v in counter.items():
            num = min(v, num)
            
        def canAssign(val):
            high, low = val+1, val  # possible number of items in a group
            res = 0
            for k, v in counter.items():
                q, r = divmod(v, high)
                if r == 0:
                    res += q
                elif low - r <= q:
                    res += q+1
                else:
                    return 0, False
            return res, True
        
        
        for base in range(num, 0, -1):
            tot, boolean = canAssign(base)
            if boolean:
                return tot
