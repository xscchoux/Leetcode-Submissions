# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
# with extra space
#         if not head:
#             return None
#         head1 = oddHead = ListNode(0) 
#         head2 = evenHead = ListNode(0)
        
#         isOdd = True
        
#         while head:
#             if isOdd:
#                 oddHead.next = head
#                 oddHead = oddHead.next
#             else:
#                 evenHead.next = head
#                 evenHead = evenHead.next
#             head = head.next
#             isOdd = not isOdd
        
#         evenHead.next = None
#         oddHead.next = head2.next
#         return head1.next

# without extra space
        if not head:
            return None
        oddHead, evenHead = head, head.next
        odd, even = oddHead, evenHead
        while even and even.next:
            odd.next = even.next
            odd = even.next
            even.next = odd.next
            even = odd.next
            
        odd.next = evenHead
        
        return oddHead