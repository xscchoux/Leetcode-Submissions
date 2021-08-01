class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
# stack
# Time complexity:O(n), Space complexity:O(n)
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
    
# two pointers
# Time complexity:O(n), Space complexity:O(1)
        N = len(height)
        left, right = 0, N-1
        leftMax = rightMax = 0
        res = 0
        
        while left <= right:
            if leftMax < rightMax:
                if height[left] > leftMax:
                    leftMax = height[left]
                else:
                    res += leftMax - height[left]
                left += 1
            else:
                if height[right] > rightMax:
                    rightMax = height[right]
                else:
                    res += rightMax - height[right]
                right -= 1
        
        return res