from sortedcontainers import SortedList
class Solution:
    def maxProfit(self, prices: List[int], profits: List[int]) -> int:
        # https://github.com/kamyu104/LeetCode-Solutions/blob/master/Python/maximum-profitable-triplets-with-increasing-prices-ii.py
        N = len(prices)
        res = float('-inf')
            
        leftSL = SortedList()
        left = [float('-inf')]*N
        
        for i in range(N):
            ind = leftSL.bisect_left((prices[i], ))
            if ind-1 >= 0:
                left[i] = leftSL[ind-1][1]   # get maximum profit with price less than prices[i]
            if ind-1 >= 0 and leftSL[ind-1][1] >= profits[i]:
                continue  # don't add this element in sortedList
            leftSL.add((prices[i], profits[i]))
            idxInsert = leftSL.bisect_left((prices[i], profits[i]))
            while idxInsert + 1 < len(leftSL) and leftSL[idxInsert + 1][1] <= profits[i]:
                del leftSL[idxInsert+1]
                
        rightSL = SortedList()
        right = [float('-inf')]*N
        
        for i in range(N-1, -1, -1):
            ind = rightSL.bisect_left((-prices[i], ))
            if ind-1 >= 0:
                right[i] = rightSL[ind-1][1]   # get maximum profit with price greater than prices[i]
            if ind-1 >= 0 and rightSL[ind-1][1] >= profits[i]:
                continue  # don't add this element in sortedList
            rightSL.add((-prices[i], profits[i]))
            idxInsert = rightSL.bisect_left((-prices[i], profits[i]))
            while idxInsert + 1 < len(rightSL) and rightSL[idxInsert + 1][1] <= profits[i]:
                del rightSL[idxInsert+1]
        
        for i in range(N):
            res = max(res, left[i] + profits[i] + right[i])
        
        return res if res > 0 else -1 