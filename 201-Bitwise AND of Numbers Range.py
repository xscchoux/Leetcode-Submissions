class Solution(object):
    def rangeBitwiseAnd(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
# bit shift
        shift = 0
        while left < right:
            left >>= 1
            right >>= 1
            shift += 1
            
        return right << shift
    
# Brian Kernighan's Algorithm
        while right!=0 and right>left:
            right = right & (right-1)
            
        return right