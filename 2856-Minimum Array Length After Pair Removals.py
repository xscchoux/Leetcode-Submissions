class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
# binary search O(nlogn)
        N = len(nums)
        left, right = 0, N//2
        
        def isOK(numbers):
            for i in range(numbers):
                if nums[i] >= nums[N-numbers+i]:
                    return False
            return True
        
        while left + 1 < right:
            mid = left + (right-left)//2
            if isOK(mid):
                left = mid
            else:
                right = mid
        
        if isOK(right):
            return N - 2*right
        else:
            return N - 2*left


# Greedy O(n)
        N = len(nums)
        left, right = 0, (N+1)//2
        cnt = 0
        
        while left < right and right < N:
            if nums[left] < nums[right]:
                left += 1
                cnt += 1
            right += 1
            
        return N - cnt*2
    
# Greedy + Binary Search O(logn)
# Find the count of the most common item. If it's more than a half, some of this number cannot be cancelled out.

        N = len(nums)
        mid = nums[N//2]  # value of possibly most common item 
        cnt = bisect_right(nums, mid) - bisect_left(nums, mid)
        if cnt > N//2:    # make sure nums[N//2] is most common item 
            return cnt - (N - cnt)  # number of most common item - (most common items that pair up iwth other items)
        else:
            return N%2