class Solution(object):
    def verifyPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: bool
        """
        _min = float('-inf')
        stack = [float('inf')]
        
        for val in preorder:
            if val < _min:
                return False
            while val > stack[-1]:
                _min = stack.pop()
            stack.append(val)
        
        return True