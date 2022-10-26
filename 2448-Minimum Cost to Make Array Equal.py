class Solution(object):
    def minCost(self, nums, cost):
        """
        :type nums: List[int]
        :type cost: List[int]
        :rtype: int
        """
# https://www.youtube.com/watch?v=R5Ggp7fGNVA&ab_channel=HuifengGuan
        arr = []
        for i in range(len(nums)):
            arr.append((nums[i], cost[i]))
        arr.sort()

        preCost = [arr[0][1]]
        for i in range(1, len(arr)):
            preCost.append(preCost[-1] + arr[i][1])
            
        leftCost = [0]
        for j in range(1, len(arr)):
            leftCost.append(leftCost[-1] + (arr[j][0]-arr[j-1][0])*preCost[j-1])
        
        rightCost = [0]
        for j in range(len(arr)-2, -1, -1):
            rightCost.append(rightCost[-1] + (arr[j+1][0]-arr[j][0])*(preCost[-1]-preCost[j]))
        rightCost = rightCost[::-1]
        
        res = float('inf')
        for i in range(len(nums)):
            res = min(res, leftCost[i] + rightCost[i])
        return res
    
# solution2, get median
        arr = []
        for i in range(len(nums)):
            arr.append((nums[i], cost[i]))
        arr.sort()
        
        tot = sum(cost)
        curr = 0
        k = 0
        for j in range(len(arr)):
            curr += arr[j][1]
            if curr >= tot//2:
                k = j # index of median
                break

        res = 0
        for i in range(len(nums)):
            res += abs(nums[i] - arr[k][0])*cost[i]
            
        return res