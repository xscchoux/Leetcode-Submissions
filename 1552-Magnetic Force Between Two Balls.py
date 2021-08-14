class Solution(object):
    def maxDistance(self, position, m):
        """
        :type position: List[int]
        :type m: int
        :rtype: int
        """
        position.sort()
        
        def putBalls(diff):
            count = 1
            prev = position[0]
            for i in range(1, len(position)):
                if position[i] - prev >= diff:
                    count += 1
                    if count >= m:
                        return True
                    prev = position[i]
            return False
        
        left, right = 1, (position[-1] - position[0]) // (m - 1)
        while left + 1 < right:
            mid = left + (right-left)//2
            if putBalls(mid):
                left = mid
            else:
                right = mid
        
        if putBalls(right):
            return right
        else:
            return left