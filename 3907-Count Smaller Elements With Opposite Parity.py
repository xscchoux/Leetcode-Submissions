class Solution:
    def countSmallerOppositeParity(self, nums: list[int]) -> list[int]:
        N = len(nums)
        slOdd, slEven = SortedList(), SortedList()
        res = []
        
        for i in range(N-1, -1, -1):
            if nums[i]%2:
                idx = slEven.bisect_right(nums[i]-1)
                res.append(idx)
                slOdd.add(nums[i])
            else:
                idx = slOdd.bisect_right(nums[i]-1)
                res.append(idx)
                slEven.add(nums[i])                


        return res[::-1]