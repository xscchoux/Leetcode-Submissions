class Solution(object):
    def canSeePersonsCount(self, heights):
        """
        :type heights: List[int]
        :rtype: List[int]
        """
        N = len(heights)
        res = [0]*N
        stack = []
        
        for i in range(len(heights)):
            while stack and heights[i] >= heights[stack[-1]]:
                res[stack.pop()] += 1
            if stack:
                res[stack[-1]] += 1
            stack.append(i)
            
        return res