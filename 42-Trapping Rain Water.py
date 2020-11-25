class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        stack = []
        res = 0
        for i in range(len(height)):
            while stack and height[i] > height[stack[-1]]:
                currIndex = stack.pop()
                if stack:
                    h = min(height[i], height[stack[-1]]) - height[currIndex]
                    w = i - stack[-1] - 1
                    res += h*w
            stack.append(i)
        return res