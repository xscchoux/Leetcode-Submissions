# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        hmap = {0:dummy}
        _sum = 0
        
        while head:
            _sum += head.val
            if _sum in hmap:
# delete unnecessary keys
                tmp = _sum
                start = hmap[tmp].next
                while start!=head:
                    tmp += start.val
                    del hmap[tmp]
                    start = start.next
# connect
                hmap[_sum].next = head.next
            else:
                hmap[_sum] = head
            head = head.next
            
        return dummy.next