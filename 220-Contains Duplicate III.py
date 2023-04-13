from sortedcontainers import SortedList
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        sl = SortedList()
        
        for i in range(len(nums)):
            if i-k-1 >= 0:
                sl.remove(nums[i-k-1])
                
            left = sl.bisect_left(nums[i]-t)
            right = sl.bisect_right(nums[i]+t)
            
            if left != right:
                return True

            sl.add(nums[i])
        
        return False


# bucket sort (put num in buckets based on valueDiff, faster but hard to implement)
        
        bucket = dict()
        for i in range(len(nums)):
            idx = nums[i]//t if t != 0 else nums[i]  # index of bucket
            for prevIdx in [idx-1, idx, idx+1]:
                if prevIdx in bucket and abs(nums[i] - bucket[prevIdx]) <= t:
                    return True
            bucket[idx] = nums[i]
            if i >= k:
                removeIdx = nums[i-k]//t if t != 0 else nums[i-k]
                del bucket[removeIdx]
            
            
        return False