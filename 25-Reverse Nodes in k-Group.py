# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return None;
        curr = head
        for _ in range(k-1):
            curr = curr.next
            if not curr:
                return head
        
        prev = self.reverseKGroup(curr.next,k)
        
        for _ in range(k):
            tmp = head.next
            head.next = prev
            prev = head
            head = tmp
        
        return prev