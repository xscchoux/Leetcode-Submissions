# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        nodeList = [root]
        
        def findLeaves(nodeList):
            currList = []
            for node in nodeList:
                if node.left:
                    currList.append(node.left)
                if node.right:
                    currList.append(node.right)
            if not currList:
                return sum([node.val for node in nodeList])
            
            return findLeaves(currList)
        
        return findLeaves(nodeList)