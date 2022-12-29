# """
# This is BinaryMatrix's API interface.
# You should not implement it, or speculate about its implementation
# """
#class BinaryMatrix(object):
#    def get(self, x, y):
#        """
#        :type x : int, y : int
#        :rtype int
#        """
#
#    def dimensions:
#        """
#        :rtype list[]
#        """
class Solution(object):
    def leftMostColumnWithOne(self, binaryMatrix):
        """
        :type binaryMatrix: BinaryMatrix
        :rtype: int
        """
        row, col = binaryMatrix.dimensions()
        
        result = -1
        r = 0
        c = col-1
        
        while r<row and c>=0:
            if binaryMatrix.get(r,c) == 1:
                result = c
                c -= 1
            else:
                r+=1
                
        return result