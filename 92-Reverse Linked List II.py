# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        
        dummyhead = ListNode(0)
        dummyhead.next = head
        first = dummyhead
        
        for _ in range(m-1):
            first = first.next
        
        dummy = dummy2 = first.next
        
        for _ in range(n-m+1):
            dummy2 = dummy2.next

        prev = dummy2
        curr = dummy
        
        for i in range(n-m+1):
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp

        first.next = prev
        
        return dummyhead.next