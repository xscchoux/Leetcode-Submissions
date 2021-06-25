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
        
# Recursive
        self.leftHead = rightHead = head
        self.stop = False
        def recurse(rightHead, left, right):
            if right == 1:
                return
            
            rightHead = rightHead.next
            
            if left > 1:
                self.leftHead = self.leftHead.next
                
            recurse(rightHead, left-1, right-1)
            
            if self.stop:
                return
            
            if self.leftHead == rightHead or rightHead.next == self.leftHead:
                self.stop = True
                return
            
            self.leftHead.val, rightHead.val = rightHead.val, self.leftHead.val
            self.leftHead = self.leftHead.next
             
        recurse(rightHead, left, right)
        return head


# Iterative
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