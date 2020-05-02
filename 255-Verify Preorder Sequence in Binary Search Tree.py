class Solution(object):
    def verifyPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype: bool
        """
# Time: O(n), Space: O(n)
        stack = []
        _min = float('-inf')
        for i in range(len(preorder)):
            if preorder[i] < _min:
                return False
            while stack and preorder[i] > stack[-1]:
                _min = stack.pop()
            stack.append(preorder[i])
            
        return True

# Time: O(n), Space: O(1)
        _min = float('-inf')
        index = -1
        for i in range(len(preorder)):
            if preorder[i] < _min:
                return False
            while index>=0 and preorder[i] > preorder[index]:
                _min = preorder[index]
                index -= 1
            index+=1
            preorder[index] = preorder[i]
            
        return True