class Solution:
    def maximumSumOfHeights(self, maxHeights: List[int]) -> int:
        res = 0
        
        def cal(arr):
            N = len(arr)
            preSum = [0]*N
            stack = []
            running = 0
            for i in range(N):
                # running += arr[i]
                while stack and arr[i] < arr[stack[-1]]:
                    idx = stack.pop()
                    if stack:
                        running -= (idx-stack[-1])*arr[idx]
                    else:
                        running -= (idx+1)*arr[idx]
                if stack:
                    running += (i-stack[-1])*arr[i]
                else:
                    running += (i+1)*arr[i]
                stack.append(i)
                preSum[i] = running
            return preSum
        
        leftPreSum = cal(maxHeights)
        rightPreSum = cal(maxHeights[::-1])[::-1]

        for i in range(len(maxHeights)):
            res = max(res, leftPreSum[i] - maxHeights[i] + rightPreSum[i])
        
        return res