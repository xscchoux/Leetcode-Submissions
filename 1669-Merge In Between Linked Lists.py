# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        """
        :type list1: ListNode
        :type a: int
        :type b: int
        :type list2: ListNode
        :rtype: ListNode
        """
        head2 = end2 = list2
        
        while end2.next:
            end2 = end2.next
        
        head1 = curr1 = list1
        
        cut1 = cut2 = None
        count = 0
        while True:
            if count == a-1:
                cut1 = curr1
            if count == b:
                cut2 = curr1.next
                curr1.next = None
                break
            curr1 = curr1.next
            count += 1
        cut1.next = head2
        end2.next = cut2
        
        return head1