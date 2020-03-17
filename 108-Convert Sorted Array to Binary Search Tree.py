# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

    def sortedArrayToBST(self, nums):
        if not nums:
            return None
        def divideAndConquer(left, right):
            if left > right:
                return None
            mid = left + (right-left)//2
            node = TreeNode(nums[mid])
            node.left = divideAndConquer(left, mid-1)
            node.right = divideAndConquer(mid+1, right)
            return node
        
        return divideAndConquer(0, len(nums)-1)