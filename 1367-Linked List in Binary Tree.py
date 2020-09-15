from collections import deque
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
    def isSubPath(self, head, root):
        """
        :type head: ListNode
        :type root: TreeNode
        :rtype: bool
        """
# two DFS
        if not root:
            return False
        if head.val == root.val and (self.isPath(head.next, root.left) or self.isPath(head.next, root.right)):
            return True
        
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
        
    def isPath(self, head, root):
        if not head:
            return True
        if not root:
            return False
        if head.val == root.val and (self.isPath(head.next, root.left) or self.isPath(head.next, root.right)):
            return True
        else:
            return False

# BFS + DFS (quicker)
        if not root:
            return False
        queue = deque([root])
        while queue:
            x = queue.popleft()
            y = head
            if self.search(x, y):
                return True
            if x.left:
                queue.append(x.left)
            if x.right:
                queue.append(x.right)
        return False
    
    
    def search(self, root, head):
        if not head:
            return True
        if not root:
            return False
        if root.val == head.val and (self.search(root.left, head.next) or self.search(root.right, head.next)):
            return True
        else:
            return False