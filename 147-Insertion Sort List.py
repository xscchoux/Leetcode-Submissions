# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return None
        
        dummy = ListNode(float('-inf'))
        dummy.next = head
        curr = dummy
        
        while curr.next:
            if curr.next.val >= curr.val:
                curr = curr.next
            else:
                tmp = curr.next
                curr.next = curr.next.next
                prev = dummy
                while prev.next.val < tmp.val:
                    prev = prev.next
                tmp.next = prev.next
                prev.next = tmp
        
        return dummy.next