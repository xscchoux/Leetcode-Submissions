# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        
        head1 = head1Curr = ListNode(0) 
        head2 = head2Curr = ListNode(0)
        
        while head:
            if head.val < x:
                head1Curr.next = head
                head1Curr = head1Curr.next
            else:
                head2Curr.next = head
                head2Curr = head2Curr.next
            head = head.next
        
        head2Curr.next = None
        
        head1Curr.next = head2.next
        
        return head1.next