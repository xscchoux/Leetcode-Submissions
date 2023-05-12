# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitCircularLinkedList(self, list: Optional[ListNode]) -> List[Optional[ListNode]]:
        slow = fast = list
        
        while fast.next != list and fast.next.next != list:
            slow = slow.next
            fast = fast.next.next
            
        second = slow.next
        
        if fast.next == list:
            fast.next = second
        else:
            fast.next.next = second
        
        slow.next = list
        
        return [list, second]