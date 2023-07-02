# # sortedList
from sortedcontainers import SortedList
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        res = 0
        left = 0
        N = len(nums)
        sl = SortedList()
        
        for i in range(N):
            sl.add(nums[i])
            while sl[-1] - sl[0] > 2:
                sl.remove(nums[left])
                left += 1
            res += (i-left+1)
        
        return res

# deque
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        maxQ, minQ = deque(), deque()
        N = len(nums)
        left = res = 0
        
        for i in range(N):
            
            # keep all indexes and numbers greater or equal to nums[i], monotonically decreasing
            while maxQ and nums[maxQ[-1]] < nums[i]:
                maxQ.pop()
            maxQ.append(i)
            
            # keep all indexes and numbers smaller or equal to nums[i], monotonically increasing
            while minQ and nums[minQ[-1]] > nums[i]:
                minQ.pop()
            minQ.append(i)            
            
            while nums[maxQ[0]] - nums[minQ[0]] > 2:
                if maxQ[0] < minQ[0]:
                    left = maxQ[0] + 1
                    maxQ.popleft()
                else:
                    left = minQ[0] + 1
                    minQ.popleft()
            
            res += (i-left+1)
            
        return res

# heap
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        maxHeap, minHeap = [], []
        N = len(nums)
        left = res = 0
        
        for i in range(N):
            heappush(maxHeap, (-nums[i], i))
            heappush(minHeap, (nums[i], i))
            while -maxHeap[0][0] - minHeap[0][0] > 2:
                left += 1
                while maxHeap and maxHeap[0][1] < left:
                    heappop(maxHeap)
                while minHeap and minHeap[0][1] < left:
                    heappop(minHeap)
            
            res += (i - left + 1)
            
        return res