from sortedcontainers import SortedList
class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:

# sorted list, O(nlogn)
        sl = SortedList()
        sl.add(0)
        res = tot = 0
        
        # lower <= preSum[i] - preSum[j] <= upper
        # preSum[i] - upper <= preSum[j(left)]
        # preSum[i] - lower < preSum[j(right)]
        
        for num in nums:
            tot += num
            left = sl.bisect_left(tot-upper)
            right = sl.bisect_left(tot-(lower-1))
            res += (right-left)
            sl.add(tot)
            
        return res
        
    
# divide and conquer (merge sort)，O(nlogn)
        preSum = [0]*(len(nums)+1)
        for i in range(len(nums)):
            preSum[i+1] = preSum[i] + nums[i]
    
        def mergeSort(start, end):
            if end <= start:
                return 0
            
            count = 0
            mid = start + (end-start)//2
            count += (mergeSort(start, mid) + mergeSort(mid+1, end))
            j = k = mid+1  #
            for i in range(start, mid+1):
                while j <= end and preSum[j] - preSum[i] < lower:
                    j += 1
                while k <= end and preSum[k] - preSum[i] <= upper:
                    k += 1
                count += (k-j)
                
            # This is O(n) because both preSum[start:mid+1] and preSum[mid+1:end+1] are sorted
            preSum[start:end+1] = sorted(preSum[start:end+1]) 

            return count
                
        return mergeSort(0, len(preSum)-1)