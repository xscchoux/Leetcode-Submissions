# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        
        arr = []
        while head:
            arr.append(head.val)
            head = head.next

        l, r = 0, len(arr)-1
        
        def dfs(left, right):
            if left > right:
                return None
            mid = left + (right-left)//2
            curr = ListNode(arr[mid])
            curr.left = dfs(left, mid-1)
            curr.right = dfs(mid+1, right)
            
            return curr
        
        return dfs(l, r)


# better
        p = head
        length = 0
        while p:
            p = p.next
            length += 1
    
        self.head = head
        
        def dfs(left, right):
            if right < left:
                return None
            mid = left + (right-left)//2
            leftNode = dfs(left, mid-1)
            
            curr = ListNode(self.head.val)
            curr.left = leftNode
            self.head = self.head.next
            
            rightNode = dfs(mid+1, right)
            curr.right = rightNode
            return curr
        
        return dfs(0, length-1)