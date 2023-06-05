class Solution:
    def countTheNumOfKFreeSubsets(self, nums: List[int], k: int) -> int:
        hmap = defaultdict(list)
        
        for num in nums:
            hmap[num%k].append(num)
        
        def dp(arr):
            arr.sort()
            take, noTake = 0, 1
            for i in range(len(arr)):
                prevTake = take
                prevNoTake = noTake
                if i >= 1 and arr[i] == arr[i-1] + k:
                    take = prevNoTake
                    noTake = prevTake + prevNoTake
                else:
                    take = prevTake + prevNoTake
                    noTake = prevTake + prevNoTake
            return take + noTake
                
        res = 1
        for v in hmap.values():
            res = res*dp(v)
            
        return res