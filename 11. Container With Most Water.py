class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxArea = 0
        left, right = 0, len(height)-1
        
        while left < right:
            if height[left] < height[right]:
                maxArea = max(maxArea, height[left]*(right-left))
                left += 1
            else:
                maxArea = max(maxArea, height[right]*(right-left))
                right -= 1
                
        return maxArea