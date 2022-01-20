class Solution(object):
    def findPeakGrid(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        top, down = 0, len(mat)-1
        
        while top + 1 < down:
            mid = top + (down-top)//2
            if max(mat[mid]) > max(mat[mid+1]):
                down = mid
            else:
                top = mid
                
        if max(mat[top]) > max(mat[top+1]):
            return [top, mat[top].index(max(mat[top]))]
        else:
            return [down, mat[down].index(max(mat[down]))]