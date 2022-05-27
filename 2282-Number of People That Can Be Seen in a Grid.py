class Solution(object):
    def seePeople(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
                
        def count(arr):
            l = len(arr)
            res = [0]*l
            stack = []
            
            for i in range(len(arr)):
                while stack and arr[stack[-1]] < arr[i]:
                    ind = stack.pop()
                    res[ind] += 1
                if stack:
                    res[stack[-1]] += 1
                    if arr[stack[-1]] == arr[i]:
                        stack[-1] = i
                        continue
                stack.append(i)
            return res
        
        for r in range(len(heights)):
            res.append(count(heights[r]) )
        
        if len(heights) > 1:
            res_col = [count(arr_col) for arr_col in zip(*heights)]
            for r in range(len(heights)):
                for c in range(len(heights[0])):
                    res[r][c] += res_col[c][r]
        
        return res