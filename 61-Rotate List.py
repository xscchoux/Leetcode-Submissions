# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
# first try, two pointors
        if not head or k == 0:
            return head
        
        tmp = head
        length = 0
        
        # calculate the number of nodes
        while tmp:
            length+=1
            tmp = tmp.next
        
        slow = fast = head
        for _ in range(k%length):
            fast = fast.next
        
        while fast.next:
            slow = slow.next
            fast = fast.next
        
        # when slow is the last node
        if not slow.next:
            return head
        
        newHead = slow.next
        slow.next = None
        fast.next = head
        
        return newHead

# connect tail to head
        if not head or k == 0:
            return head
        
        count = 1
        tmp = head
        
        while tmp.next:
            count += 1
            tmp = tmp.next
        
        tmp.next = head
        
        for _ in range(count-k%count):
            tmp = tmp.next
        
        newHead = tmp.next
        tmp.next = None
        
        return newHead