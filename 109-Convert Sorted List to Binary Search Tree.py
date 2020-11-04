# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        output = []
        while head:
            output.append(head.val)
            head = head.next

        def dfs(output):
            if not output:
                return None
            lo, hi = 0, len(output)-1
            mid = (lo+hi)//2
            root = TreeNode(output[mid]) 
            root.left = dfs(output[:mid])
            root.right = dfs(output[mid+1:])
            return root
            
        
        return dfs(output)