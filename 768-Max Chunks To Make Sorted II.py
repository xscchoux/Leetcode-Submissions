class Solution(object):
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
# sol 1, O(nlogn)
        sortedArr = arr[:]
        sortedArr.sort()
        sum1 = sum2 = 0
        count = 0
        
        for i in range(len(arr)):
            sum1 += arr[i]
            sum2 += sortedArr[i]
            if sum1 == sum2:
                count += 1
                sum1 = 0
                sum2 = 0
        return count
    
# sol 2, stack, O(n), very tricky

        curMax = 0
        stack = []
        for i in range(len(arr)):
            if stack and stack[-1] > arr[i]:
                while stack and stack[-1] > arr[i]:
                    stack.pop()
                stack.append(curMax)
            else:
                stack.append(arr[i])
                curMax = arr[i]
                
        return len(stack)