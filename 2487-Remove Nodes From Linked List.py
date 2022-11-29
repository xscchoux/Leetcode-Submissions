# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        
        stack = []
        while node:
            while stack and node.val > stack[-1].val:
                stack.pop()
            if stack:
                stack[-1].next = node
            stack.append(node)
            node = node.next
        
        return stack[0]