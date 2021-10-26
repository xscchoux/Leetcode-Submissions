# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicatesUnsorted(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(float('-inf'))
        dummy.next = head
        tmp = head
        count = collections.defaultdict(int)
        
        while tmp:
            count[tmp.val] += 1
            tmp = tmp.next
        prev = dummy
        
        while prev.next:
            if count[prev.next.val] >= 2:
                prev.next = prev.next.next
            else:
                prev = prev.next
                
        return dummy.next