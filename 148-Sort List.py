# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        slow = fast = head
        prev = ListNode(0)
        prev.next = head
        
        while fast and fast.next:
            prev = prev.next
            slow = slow.next
            fast = fast.next.next
            
        prev.next = None
        one = self.sortList(head)
        two = self.sortList(slow)
        
        return self.merge(one,two)
    
    def merge(self, one, two):
        dummy = curr = ListNode(0)
        while one and two:
            if one.val <= two.val:
                curr.next = one
                one = one.next
            else:
                curr.next = two
                two = two.next
            curr = curr.next
        curr.next = one or two
        return dummy.next