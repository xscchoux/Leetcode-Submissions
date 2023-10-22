class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:

    # monotonic stack, O(N)

        N = len(nums)
        left = [-1]*N
        stack = []
        for i in range(N):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            if stack:
                left[i] = stack[-1]
            stack.append(i)
        
        right = [N]*N
        stack = []
        for i in range(N-1, -1, -1):
            while stack and nums[stack[-1]] >= nums[i]:
                stack.pop()
            if stack:
                right[i] = stack[-1]
            stack.append(i)

        res = 0
        
        for i in range(N):
            if k > left[i] and k < right[i]:
                res = max(res, nums[i]*(right[i]-left[i]-1))
        
        return res


    # greedy, expanding from the kth element, O(N)

        N = len(nums)
        left = right = k
        mn = res = nums[k]
        
        while left >= 0 and right < N:
            leftVal = rightVal = 0
            if left - 1 >= 0:
                leftVal = nums[left-1]
            if right + 1 < N:
                rightVal = nums[right+1]
            
            # include the larger of the left or the right
            
            if leftVal > rightVal:
                mn = min(mn, leftVal)
                left -= 1
            else:
                mn = min(mn, rightVal)
                right += 1
            
            res = max(res, mn*(right-left+1))
        
        return res