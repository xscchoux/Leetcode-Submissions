class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
# monotonic stack
# O(n)

# https://www.jiuzhang.com/solutions/largest-rectangle-in-histogram
        if not heights:
            return 0
        
        stack = []
        heights.append(-1)
        res = 0
        for i in range(len(heights)):
            while stack and heights[i] < heights[stack[-1]]:
                index = stack.pop()
                h = heights[index]
                if not stack:
                    w = i
                else:
                    w = i - stack[-1] - 1
                res = max(res, w*h)
            stack.append(i)
        
        return res