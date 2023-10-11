class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
    # First try
        arr = []
        for start, end in flowers:
            arr.append((start, 1))
            arr.append((end+1, -1))
        
        arr.sort()
        preSum = [(0, 0)]
        curr = 0
        
        for val, flag in arr:
            if flag == 1:
                curr += 1
            else:
                curr -= 1
            preSum.append((val, curr))

        def bs(preSum, p):
            left, right = 0, len(preSum)-1
            while left + 1 < right:
                mid = left + (right-left)//2
                if preSum[mid][0]<=p:
                    left = mid
                else:
                    right = mid
            if preSum[right][0] <= p:
                return right
            return left
        
        res = []
        for p in people:
            idx = bs(preSum, p)
            res.append(preSum[idx][1])
            
        return res
        
    # Much better
        
        startArr, endArr = [], []
        for start, end in flowers:
            startArr.append(start)
            endArr.append(end+1)
        
        startArr.sort()
        endArr.sort()
        
        res = []
        
        for p in people:
            gain = bisect_right(startArr, p)
            loss = bisect_right(endArr, p)
            res.append(gain-loss)
            
        return res