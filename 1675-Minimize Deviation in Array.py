import heapq
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        
# make all numbers is the array even, and calculate minimum diff

        pq = [] # return current maximum
        currMin = float('inf')
        
        for num in nums:
            if num%2:
                currMin = min(num*2, currMin)
                heappush(pq, -num*2)
            else:
                currMin = min(currMin, num)
                heappush(pq, -num)
                
        res = float('inf')
        
        while True:
            currMax = -heappop(pq)
            res = min(res, currMax - currMin)
            if currMax%2:
                break
            else:
                currMin = min(currMin, currMax//2)
                heappush(pq, -currMax//2)
            
        return res