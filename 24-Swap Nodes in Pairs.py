# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        curr = head
        prev = dummy = ListNode(0)
        prev.next = head
        
        while curr and curr.next:
            tmp = curr.next
            curr.next = tmp.next
            prev.next = tmp
            tmp.next = curr
            prev = curr
            curr = curr.next
        
        return dummy.next