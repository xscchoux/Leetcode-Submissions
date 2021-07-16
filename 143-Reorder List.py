# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
# two pointer
        slow = fast = head
        
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        newHead = slow.next
        slow.next = None
        prev = None
        
        while newHead:
            tmp = newHead.next
            newHead.next = prev
            prev = newHead
            newHead = tmp
        
        pointer = head
        while pointer and prev:
            pointerNxt = pointer.next
            prevNxt = prev.next
            pointer.next = prev
            prev.next = pointerNxt
            pointer = pointerNxt
            prev = prevNxt
        
        return head
        
# stack
        stack = []
        tmp = head
        length = 0
        
        while tmp:
            length += 1
            stack.append(tmp)
            tmp = tmp.next
        
        count = (length-1)//2
        tmp2 = head
        
        while count > 0:
            nxt = tmp2.next
            new = stack.pop()
            tmp2.next = new
            new.next = nxt
            tmp2 = nxt
            count-=1

        stack[-1].next = None
        
        return head