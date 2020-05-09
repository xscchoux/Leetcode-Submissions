class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        left, right = 1, num//2
        
        while left+1 < right:
            mid = left + (right-left)//2
            if mid*mid == num:
                return True
            elif mid*mid > num:
                right = mid
            else:
                left = mid
        
        if right*right == num or left*left == num:
            return True
        else:
            return False