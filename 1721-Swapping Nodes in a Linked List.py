# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        curr = head
        
        def findNode(k, curr):
            while k > 1:
                curr = curr.next
                k -= 1
            frontNode = curr
            
            endNode = head
            while curr.next:
                endNode = endNode.next
                curr = curr.next
            return frontNode, endNode
        
        frontNode, endNode = findNode(k, curr)
        frontNode.val, endNode.val = endNode.val, frontNode.val
        
        return head