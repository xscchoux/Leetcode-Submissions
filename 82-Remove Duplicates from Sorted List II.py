# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
# first Try
#         dummy = prev = ListNode(-101)
#         pvt = ListNode(-102)
#         prev.next = head
#         pvt.next = prev
#         foundDup = False
        
#         while head:
#             if head.val != prev.val:
#                 if foundDup:
#                     foundDup = False
#                     head = head.next
#                     prev = prev.next
#                     pvt.next = prev
#                 else:
#                     head = head.next
#                     prev = prev.next
#                     pvt = pvt.next
#             else:
#                 foundDup = True
#                 head = head.next
#                 prev = prev.next
                
#         if foundDup:
#             pvt.next = None
            
#         return dummy.next


# Concise solution
        dummy = prev = ListNode(-101)
        prev.next = head
        
        while head and head.next:
            if head.val == head.next.val:
                while head and head.next and head.val == head.next.val:
                    head = head.next
                prev.next = head.next
                head = head.next
            else:
                head = head.next
                prev = prev.next
        
        return dummy.next