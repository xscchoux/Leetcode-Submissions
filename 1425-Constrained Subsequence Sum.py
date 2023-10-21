from heapq import *
class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        # heap
        pq = [(0, -1)]  # value, idx
        res = 0
        for i in range(len(nums)):
            while pq and i - pq[0][1] > k:
                heappop(pq)
                
            preValue, preIdx = pq[0]
            curr = max(nums[i], nums[i]-preValue)
            res = max(res, curr)
            heappush(pq, (-curr, i))

        if res == 0:
            return max(nums)
        return res
    
        # DP + deque
        dq = deque([(0, -1)])
        dp = [0]*len(nums)
        
        for i in range(len(nums)):
            # remove old ones
            if dq and i - dq[0][1] > k:
                dq.popleft()
                
            if dq:
                curr = max(nums[i], dq[0][0] + nums[i])
            else:
                curr = nums[i]
                
            dp[i] = curr
            # monotonic decreasing
            while dq and dq[-1][0] <= curr:
                dq.pop()
            
            dq.append((curr, i))

        return max(dp)