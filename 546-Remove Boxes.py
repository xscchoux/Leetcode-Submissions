class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        def dfs(left, right, same): # left index, right index, count of numbers same with boxes[left] (do not include boxes[left] itself)
            if left > right:
                return 0
            if (left, right, same) in memo:
                return memo[(left, right, same)]
            
            tmpL = left
            count = same
            while tmpL <= right and boxes[tmpL] == boxes[left]:
                tmpL+=1
                count+=1
            
            res = dfs(tmpL, right, 0) + count**2

            for i in range(tmpL, right+1):
                if boxes[i] != boxes[left]: continue
                if boxes[i]==boxes[left] and boxes[i-1]==boxes[left]: continue

                res = max(res, dfs(tmpL, i-1, 0) + dfs(i, right, count))
            
            memo[(left, right, same)] = res
            return res
        memo = {}
        ans = dfs(0, len(boxes)-1, 0)
        return ans